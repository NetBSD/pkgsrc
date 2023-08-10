# $NetBSD: Makefile,v 1.28 2023/08/10 07:19:32 adam Exp $

DISTNAME=	jpegoptim-1.5.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kokkonen.net/tjko/projects.html
COMMENT=	JPEG optimizer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
