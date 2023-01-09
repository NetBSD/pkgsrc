# $NetBSD: Makefile,v 1.12 2023/01/09 20:08:28 fcambus Exp $

DISTNAME=	jpeginfo-1.6.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kokkonen.net/tjko/projects.html
COMMENT=	Generates informative listings from JPEG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
