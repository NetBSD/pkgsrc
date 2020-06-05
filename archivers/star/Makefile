# $NetBSD: Makefile,v 1.51 2020/06/05 17:04:31 micha Exp $

DISTNAME=	schily-2020-05-25
PKGNAME=	star-1.6.1
PKGREVISION=	8
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	Unique standard tape archiver
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake-[0-9]*:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

# The default location is /etc/default/star
# We patch the documentation appropriately. Additionally, we also install
# INSTALL.pkgsrc stating the reasons we do this, as required by the license.
STAR_CONF?=	${PKG_SYSCONFDIR}/star

CONF_FILES=	${PREFIX}/share/examples/star/star ${STAR_CONF}
SPECIAL_PERMS+=	${PREFIX}/share/examples/star/star ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644
AUTO_MKDIRS=	yes

# Configure config file location
SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix+=	star/star.1
SUBST_FILES.fix+=	star/star.dfl
SUBST_FILES.fix+=	star/defaults.c
SUBST_SED.fix=		-e "s,/etc/default/star,${STAR_CONF},g"
SUBST_MESSAGE.fix=	Replace defaults file paths.

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_SED.install=	-e 's,PKGNAME_NOREV,${PKGNAME_NOREV},'
SUBST_SED.install+=	-e 's,STAR_CONF,${STAR_CONF:Q},'

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libdeflt libfind librmt;			\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/star && ${SMAKE} ${MAKE_FLAGS}

# Process tables in manpage
.if !empty(USE_TOOLS:Mtbl)
post-build:
	cd ${WRKSRC} && if ${TEST} -f star/pkgsrc_tbl.done; then :;	\
	else								\
		${TBL} star/spax.1 >star/spax.1.tmp &&			\
		${MV} -f star/spax.1.tmp star/spax.1 &&			\
		${TBL} star/star.4 >star/star.4.tmp &&			\
		${MV} -f star/star.4.tmp star/star.4 &&			\
		${TOUCH} star/pkgsrc_tbl.done;				\
	fi
.endif

do-test:
	cd ${WRKSRC}/star && cd tests ; ${SMAKE} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/star && ${SMAKE} ${MAKE_FLAGS} install
	${INSTALL_DATA} ${WRKSRC}/star/star.dfl				\
		${DESTDIR}${PREFIX}/share/examples/star/star
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/star/INSTALL.pkgsrc

.include "../../mk/bsd.pkg.mk"
