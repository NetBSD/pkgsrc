# $NetBSD: Makefile,v 1.47 2024/05/29 16:31:57 adam Exp $

DISTNAME=	Renaissance-0.9.0
PKGREVISION=	27
CATEGORIES=	devel gnustep
MASTER_SITES=	http://www.gnustep.it/Renaissance/Download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/Renaissance/
COMMENT=	Structured GNUstep user interface development framework

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

# "ld: -r and -pie may not be used together"
MKPIE_SUPPORTED=	no

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
