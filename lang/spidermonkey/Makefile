# $NetBSD: Makefile,v 1.25 2012/10/02 20:11:54 asau Exp $

DISTNAME=	js-1.8.0-rc1
PKGNAME=	spidermonkey-1.8.0rc1
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/js/spidermonkey/
COMMENT=	Standalone JavaScript implementation in C

WRKSRC=		${WRKDIR}/js/src

MAKE_JOBS_SAFE=	no

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_FILE=	Makefile.ref
CFLAGS+=	-DJS_USE_FDLIBM_MATH=0

MAKE_FLAGS+=	BUILD_OPT=1 LDFLAGS=${LDFLAGS:Q} PREFIX=${PREFIX:Q}

INSTALLATION_DIRS=	bin include lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD"
BUILDDIRPREFIX=	pkgsrc
.elif ${OPSYS} == "Linux"
BUILDDIRPREFIX=	Linux_All
.elif ${OPSYS} == "SunOS"
SUN_PLATFORM!=	${UNAME} -i
BUILDDIRPREFIX=	${OPSYS}${OS_VERSION}_${SUN_PLATFORM}
.else
BUILDDIRPREFIX=	${OPSYS}
.endif

.if ${OPSYS} == "Darwin"
SO_SUFFIX=dylib
.else
SO_SUFFIX=so
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX}

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/pkgsrc.mk ${WRKSRC}/config
.if ${OPSYS} == "SunOS"
	${CP} ${FILESDIR}/opensolaris.mk ${WRKSRC}/config/${BUILDDIRPREFIX}.mk
.endif
	${RM} ${WRKSRC}/lock_SunOS.s

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/js \
	  ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/libjs.${SO_SUFFIX} \
	  ${DESTDIR}${PREFIX}/lib
	${CP} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/jsautocfg.h ${WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/*.tbl ${DESTDIR}${PREFIX}/include

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
