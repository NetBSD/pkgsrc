# $NetBSD: Makefile,v 1.1.1.1 2005/02/02 21:16:34 drochner Exp $
#

DISTNAME=		rawphoto-200410220928
PKGNAME=		gimp-rawphoto-1.19
CATEGORIES=		graphics
MASTER_SITES=		http://ptj.rozeta.com.pl/Soft/rawphoto/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ptj.rozeta.com.pl/Soft/RawPhoto
COMMENT=		Digicam RAW file importer for GIMP

WRKSRC=		${WRKDIR}/rawphoto-200410220910/src
USE_BUILDLINK3=		yes
BUILD_TARGET=		build

pre-build:
	${LN} -sf ${LOCALBASE}/bin/gimptool-2.0 \
		${BUILDLINK_DIR}/bin/gimptool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawphoto \
		${PREFIX}/lib/gimp/2.0/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
