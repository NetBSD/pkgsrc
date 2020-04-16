# $NetBSD: Makefile,v 1.32 2020/04/16 09:28:39 manu Exp $

DISTNAME=	libobjc2-1.8.1
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
#PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/gnustep/gnustep-libobjc2
COMMENT=	Objective-C runtime

USE_LANGUAGES=			objc c++11
USE_TOOLS+=			gmake cmake
MAKE_FILE=			GNUmakefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread
MAKE_ENV+=			LIBOBJC=libobjc
MAKE_ENV+=			LIBOBJCXX=libobjcxx
MAKE_ENV+=			VERSION=4.6
MAKE_ENV+=			MAJOR_VERSION=4
MAKE_ENV+=			MINOR_VERSION=6
GNUSTEP_OVERRIDE_INSTALL=	YES

INSTALLATION_DIRS=              lib include/objc

do-configure:
	cd ${WRKSRC} && ${CMAKE} -Wno-dev .


.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/compiler.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
