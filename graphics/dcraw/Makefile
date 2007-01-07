# $NetBSD: Makefile,v 1.27 2007/01/07 09:13:55 rillig Exp $
#

DISTNAME=	dcraw
PKGNAME=	dcraw-8.13
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
DISTFILES=	dcraw.c dcraw.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	Raw digital camera decoder

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
LIBS+=		-lm -ljpeg

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcraw
PKG_SUPPORTED_OPTIONS=	lcms
PKG_SUGGESTED_OPTIONS=	lcms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlcms)
LIBS+=		-llcms
.include "../../graphics/lcms/buildlink3.mk"
.else
CFLAGS+=	-DNO_LCMS
.endif

do-extract:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC})

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} dcraw.c -o dcraw ${LDFLAGS} ${LIBS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
