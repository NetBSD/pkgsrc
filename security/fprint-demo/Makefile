# $NetBSD: Makefile,v 1.36 2020/03/08 16:51:07 wiz Exp $

DISTNAME=	fprint_demo-0.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	32
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://www.freedesktop.org/wiki/Software/fprint/fprint_demo/
COMMENT=	Simple GTK+ application to demonstrate libfprint's capabilities
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../security/libfprint/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
