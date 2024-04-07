# $NetBSD: Makefile,v 1.5 2024/04/07 21:33:19 wiz Exp $

DISTNAME=		xorg-sgml-doctools-1.12.1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XORG:=doc/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg documentation that does not fit anywhere else
#LICENSE=		mit?

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	xorg-sgml-doctools.pc.in

.include "../../mk/bsd.pkg.mk"
