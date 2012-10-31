# $NetBSD: Makefile,v 1.23 2012/10/31 11:17:02 asau Exp $
#

DISTNAME=	libobjc2-1.6.1
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/gnustep-libobjc2
COMMENT=	Objective-C runtime
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=			objc
USE_TOOLS+=			gmake
MAKE_FILE=			GNUmakefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread
GNUSTEP_OVERRIDE_INSTALL=	YES
NO_CONFIGURE=			YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
