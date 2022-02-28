# $NetBSD: Makefile,v 1.9 2022/02/28 10:13:53 wiz Exp $

DISTNAME=	mac-3.99-u4-b5-s7
PKGNAME=	mac-3.99u4b5s7
CATEGORIES=	audio
MASTER_SITES=	http://etree.org/shnutils/shntool/support/formats/ape/unix/3.99-u4-b5-s7/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://supermmx.org/
HOMEPAGE=	http://etree.org/shnutils/shntool/
COMMENT=	Monkey's Audio support library (for .ape files)
LICENSE=	mac-license

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-assembly=no

.include "../../mk/bsd.pkg.mk"
