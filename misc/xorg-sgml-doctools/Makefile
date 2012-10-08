# $NetBSD: Makefile,v 1.2 2012/10/08 09:57:41 asau Exp $
#

DISTNAME=		xorg-sgml-doctools-1.11
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=doc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg documentation that does not fit anywhere else
#LICENSE=		mit?

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	xorg-sgml-doctools.pc.in

.include "../../mk/bsd.pkg.mk"
