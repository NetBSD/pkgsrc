# $NetBSD: Makefile,v 1.9 2003/12/03 22:14:45 kristerw Exp $
#

DISTNAME=		tvision-0.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Turbo Vision C++ CUI library for UNIX

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
