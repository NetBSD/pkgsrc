# $NetBSD: Makefile,v 1.17 2013/10/06 17:15:35 adam Exp $

DISTNAME=	barcode-0.99
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
