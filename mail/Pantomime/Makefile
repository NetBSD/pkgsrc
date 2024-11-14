# $NetBSD: Makefile,v 1.58 2024/11/14 22:20:33 wiz Exp $

DISTNAME=	Pantomime-1.4.0
PKGREVISION=	6
CATEGORIES=	mail gnustep
MASTER_SITES=	http://download.savannah.nongnu.org/releases/gnustep-nonfsf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/gnustep-nonfsf/gnumail/
COMMENT=	Objective-C mail system class library
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc

PRIVILEGED_STAGES+=	build
PRIVILEGED_STAGES+=	clean

NO_CONFIGURE=		yes
#MAKE_JOBS_SAFE=	no
MAKE_ENV+=		ADDITIONAL_CPPFLAGS=-DMKDIR
MAKE_FILE=		GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
