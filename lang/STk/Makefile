# $NetBSD: Makefile,v 1.18 2007/02/22 19:26:37 wiz Exp $

DISTNAME=	STk-4.0.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://kaolin.unice.fr/pub/STk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kaolin.unice.fr/STk/
COMMENT=		Scheme interpreter with full access to the Tk graphical package

OSVERSION_SPECIFIC=	yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

MAKE_ENV+=		X11_LDFLAGS=${X11_LDFLAGS:Q}

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
