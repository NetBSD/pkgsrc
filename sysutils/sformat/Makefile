# $NetBSD: Makefile,v 1.19 2023/04/21 14:01:41 micha Exp $

DISTNAME=	2023-04-19
PKGNAME=	sformat-3.7
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/schilytools/schilytools/archive/
DIST_SUBDIR=	schilytools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/schilytools/schilytools/
COMMENT=	SCSI disk maintainance, formating, and ultimative repair tool
LICENSE=	cddl-1.0

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.7:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

SFORMAT_DB=	${PKG_SYSCONFDIR}/sformat.dat
CONF_FILES=	${PREFIX}/share/examples/sformat/sformat.dat ${SFORMAT_DB}
SPECIAL_PERMS+=	${PREFIX}/share/examples/sformat/sformat.dat ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644
AUTO_MKDIRS=	yes

# Configure config file location
SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix+=	sformat/datio.c
SUBST_FILES.fix+=	sformat/sformat.1
SUBST_SED.fix=		-e "s,@PKGSRC_SYSCONFDIR@,${PKG_SYSCONFDIR},g"
SUBST_MESSAGE.fix=	Replace database file path.

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in libschily libscg;		\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/sformat && ${SMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/sformat && ${SMAKE} ${MAKE_FLAGS} install
	${INSTALL_DATA} ${WRKSRC}/sformat/sformat.dat			\
		${DESTDIR}${PREFIX}/share/examples/sformat/sformat.dat

.include "../../mk/bsd.pkg.mk"
