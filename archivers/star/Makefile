# $NetBSD: Makefile,v 1.64 2023/01/25 16:18:42 micha Exp $

DISTNAME=	2023-01-12
PKGNAME=	star-1.7.0
CATEGORIES=	archivers
MASTER_SITES=	https://codeberg.org/schilytools/schilytools/archive/
DIST_SUBDIR=	schilytools

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://codeberg.org/schilytools/schilytools/
COMMENT=	Unique standard tape archiver
LICENSE=	cddl-1.0

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.6nb2:../../devel/smake
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
		${TBL} star/star.5 >star/star.5.tmp &&			\
		${MV} -f star/star.5.tmp star/star.5 &&			\
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

# Fix for pkg/56049:
# Do not install symlinks to potentially incompatible variants
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/gnutar
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gnutar.1
	${RM} ${DESTDIR}${PREFIX}/bin/suntar
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/suntar.1
	${RM} ${DESTDIR}${PREFIX}/bin/tar
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tar.1
	${RM} ${DESTDIR}${PREFIX}/bin/ustar
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ustar.1

.include "../../mk/bsd.pkg.mk"
