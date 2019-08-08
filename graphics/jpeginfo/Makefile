# $NetBSD: Makefile,v 1.11 2019/08/08 21:17:48 nia Exp $

DISTNAME=	jpeginfo-1.6.1
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
