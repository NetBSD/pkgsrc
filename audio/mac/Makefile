# $NetBSD: Makefile,v 1.8 2012/10/02 23:47:56 asau Exp $
#

DISTNAME=	mac-3.99-u4-b5-s7
PKGNAME=	mac-3.99u4b5s7
CATEGORIES=	audio
MASTER_SITES=	http://etree.org/shnutils/shntool/support/formats/ape/unix/3.99-u4-b5-s7/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://supermmx.org/
HOMEPAGE=	http://etree.org/shnutils/shntool/
COMMENT=	Monkey's Audio support library (for .ape files)
LICENSE=	mac-license

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
