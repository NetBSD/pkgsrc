# $NetBSD: Makefile,v 1.3 2007/07/21 19:42:06 adrianp Exp $
#

DISTNAME=	mac-3.99-u4-b5
PKGNAME=	mac-3.99u4b5
CATEGORIES=	audio
MASTER_SITES=	http://supermmx.org/download/linux/mac/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supermmx.org
COMMENT=	Monkey's Audio support library (for .ape files)

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
