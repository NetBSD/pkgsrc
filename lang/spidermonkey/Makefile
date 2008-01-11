# $NetBSD: Makefile,v 1.17 2008/01/11 09:36:23 bjs Exp $

DISTNAME=	js-1.60
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/js/spidermonkey/
COMMENT=	Standalone JavaScript implementation in C

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/js/src

MAKE_JOBS_SAFE=	no

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.ref
CFLAGS+=	-DJS_USE_FDLIBM_MATH=0

# JS_THREADSAFE
PTHREAD_AUTO_VARS=	yes
MAKE_FLAGS+=		BUILD_OPT=1 LDFLAGS=${LDFLAGS:Q} PREFIX=${PREFIX:Q}

INSTALLATION_DIRS=	bin include lib

DIST_HEADERS=	jsapi.h jsautocfg.h jscompat.h jslong.h	\
	       	jsosdep.h jsotypes.h jspubtd.h jstypes.h

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD"
BUILDDIRPREFIX=	pkgsrc
.elif ${OPSYS} == "Linux"
BUILDDIRPREFIX=	Linux_All
.else
BUILDDIRPREFIX=	${OPSYS}
.endif

.if ${OPSYS} == "Darwin"
SO_SUFFIX=dylib
.else
SO_SUFFIX=so
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX}

post-extract:
	${CP} ${FILESDIR}/pkgsrc.mk ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/js \
	  ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/libjs.${SO_SUFFIX} \
	  ${DESTDIR}${PREFIX}/lib
	${CP} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/jsautocfg.h ${WRKSRC}
.for f in ${DIST_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/include
.endfor

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
