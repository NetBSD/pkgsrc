# $NetBSD: Makefile,v 1.5 2002/10/25 17:35:02 wiz Exp $
#

DISTNAME=		tvision-0.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

MAINTAINER=		packages@NetBSD.org
COMMENT=		Turbo Vision C++ CUI library for UNIX

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
