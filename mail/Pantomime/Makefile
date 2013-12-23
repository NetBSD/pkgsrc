# $NetBSD: Makefile,v 1.30 2013/12/23 11:57:04 wiz Exp $

DISTNAME=	Pantomime-1.2.0
PKGREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/pantomime/
COMMENT=	Objective-C mail system class library
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc

PRIVILEGED_STAGES+=	build
PRIVILEGED_STAGES+=	clean

NO_CONFIGURE=	yes
#MAKE_JOBS_SAFE=	no
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-DMKDIR
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
