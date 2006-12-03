# $NetBSD: Makefile,v 1.10 2006/12/03 10:11:49 xtraeme Exp $

DISTNAME=	js-1.5
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/js/spidermonkey/
COMMENT=	Standalone JavaScript implementation in C

WRKSRC=		${WRKDIR}/js/src

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.ref

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
	  ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/libjs.${SO_SUFFIX} \
	  ${PREFIX}/lib
	${CP} ${WRKSRC}/${BUILDDIRPREFIX}_OPT.OBJ/jsautocfg.h ${WRKSRC}
.for f in ${DIST_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include
.endfor

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
