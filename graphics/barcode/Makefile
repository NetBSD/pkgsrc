# $NetBSD: Makefile,v 1.18 2017/08/01 17:40:12 wiz Exp $

DISTNAME=	barcode-0.99
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
