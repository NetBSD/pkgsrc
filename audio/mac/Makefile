# $NetBSD: Makefile,v 1.1.1.1 2007/01/31 21:17:18 wiz Exp $
#

DISTNAME=	mac-3.99-u4-b5
PKGNAME=	mac-3.99u4b5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mac-port/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mac-port.sourceforge.net/
COMMENT=	Monkey's Audio support library (for .ape files)

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
# really does not need "c"
USE_LANGUAGES=	c++

.include "../../mk/bsd.pkg.mk"
