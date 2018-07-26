# $NetBSD: Makefile,v 1.1 2018/07/26 14:27:23 manu Exp $

DISTNAME=	asciidir-0.6
CATEGORIES=	textproc
MASTER_SITES=	https://ftp.espci.fr/pub/asciidir/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/asciidir/
COMMENT=	Recursively remove non ASCII characters in file names
LICENSE=	original-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include	"../../converters/libiconv/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
