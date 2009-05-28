# $NetBSD: Makefile,v 1.5 2009/05/28 20:35:53 zafer Exp $
#

DISTNAME=	mac-3.99-u4-b5
PKGNAME=	mac-3.99u4b5
CATEGORIES=	audio
MASTER_SITES=	http://supermmx.org/resources/linux/mac/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supermmx.org
COMMENT=	Monkey's Audio support library (for .ape files)

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
