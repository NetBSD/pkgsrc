# $NetBSD: Makefile,v 1.10 2012/10/06 14:11:01 asau Exp $

DISTNAME=	jpeginfo-1.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	Generates informative listings from JPEG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
