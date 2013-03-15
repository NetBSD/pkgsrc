# $NetBSD: Makefile,v 1.13 2013/03/15 08:19:17 adam Exp $

DISTNAME=	jpegoptim-1.2.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	JPEG optimizer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
