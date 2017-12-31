# $NetBSD: Makefile,v 1.31 2017/12/31 11:20:03 he Exp $

DISTNAME=	libobjc2-1.6.1
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
PKGREVISION=	3
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/gnustep/gnustep-libobjc2
COMMENT=	Objective-C runtime
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=			objc
USE_TOOLS+=			gmake
MAKE_FILE=			GNUmakefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread
GNUSTEP_OVERRIDE_INSTALL=	YES
NO_CONFIGURE=			YES

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/compiler.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
