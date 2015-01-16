# $NetBSD: Makefile,v 1.17 2015/01/16 09:40:37 wiz Exp $

DISTNAME=	jpegoptim-1.4.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	JPEG optimizer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
