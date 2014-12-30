# $NetBSD: Makefile,v 1.25 2014/12/30 08:26:08 plunky Exp $

DISTNAME=	fprint_demo-0.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	22
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://reactivated.net/fprint/wiki/Fprint_demo
COMMENT=	Simple GTK+ application to demonstrate libfprint's capabilities
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../security/libfprint/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
