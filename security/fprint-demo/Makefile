# $NetBSD: Makefile,v 1.21 2013/06/06 12:55:00 wiz Exp $

DISTNAME=	fprint_demo-0.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	19
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://reactivated.net/fprint/wiki/Fprint_demo
COMMENT=	Simple GTK+ application to demonstrate libfprint's capabilities

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../security/libfprint/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
