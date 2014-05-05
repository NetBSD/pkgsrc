# $NetBSD: Makefile,v 1.25 2014/05/05 01:51:22 rh Exp $

DISTNAME=	libobjc2-1.7
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/gnustep-libobjc2
COMMENT=	Objective-C runtime
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=			objc
USE_CMAKE=			YES
#MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
