# $NetBSD: Makefile,v 1.13 2004/04/18 05:53:28 snj Exp $

DISTNAME=		OpenPTC-x11-1.0.0-2
PKGNAME=		OpenPTC-X11-1.0.02
CATEGORIES=		graphics
MASTER_SITES=		# only on NetBSD mirrors anymore

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gaffer.org/ptc/
COMMENT=		Prometheus Truecolour for X11

WRKSRC=			${WRKDIR}/OpenPTC-x11-1.0.0
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11BASE=		yes

BUILDLINK_DEPENDS.Hermes=	Hermes>=1.3.2nb1

.include "../../graphics/hermes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
