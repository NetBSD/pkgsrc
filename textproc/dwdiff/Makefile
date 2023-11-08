# $NetBSD: Makefile,v 1.11 2023/11/08 13:21:04 wiz Exp $

DISTNAME=	dwdiff-2.1.3
PKGREVISION=	6
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
USE_TOOLS+=		msgfmt msgmerge xgettext
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
