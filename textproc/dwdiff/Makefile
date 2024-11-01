# $NetBSD: Makefile,v 1.16 2024/11/01 12:54:35 wiz Exp $

DISTNAME=	dwdiff-2.1.3
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	https://os.ghalkes.nl/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://os.ghalkes.nl/dwdiff.html
COMMENT=	Word level diff program
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}

.include "options.mk"

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
