# $NetBSD: Makefile,v 1.4 2003/05/02 11:54:29 wiz Exp $
#

DISTNAME=	gnustep-objc-1.2.3
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

NO_CONFIGURE=	YES

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

.include "../../devel/gnustep-make/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
