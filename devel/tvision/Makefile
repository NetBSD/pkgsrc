# $NetBSD: Makefile,v 1.7 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=		tvision-0.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

MAINTAINER=		packages@NetBSD.org
COMMENT=		Turbo Vision C++ CUI library for UNIX

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
