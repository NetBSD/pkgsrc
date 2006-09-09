# $NetBSD: Makefile,v 1.8 2006/09/09 02:43:09 obache Exp $

DISTNAME=	js-1.5
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/js/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/js/spidermonkey/
COMMENT=	Standalone JavaScript implementation in C

WRKSRC=		${WRKDIR}/js/src

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.ref

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
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILDDIRPREFIX}_DBG.OBJ/js \
	  ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/${BUILDDIRPREFIX}_DBG.OBJ/libjs.${SO_SUFFIX} \
	  ${PREFIX}/lib
	${CP} ${WRKSRC}/${BUILDDIRPREFIX}_DBG.OBJ/jsautocfg.h ${WRKSRC}
.for f in ${DIST_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include
.endfor

.include "../../mk/bsd.pkg.mk"
