# $NetBSD: Makefile,v 1.10 2004/04/25 06:05:45 snj Exp $
#

DISTNAME=		tvision-0.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Turbo Vision C++ CUI library for UNIX

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
