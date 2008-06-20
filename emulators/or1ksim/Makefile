# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:18 joerg Exp $
#

DISTNAME=	or1ksim-0.2.0rc2
CATEGORIES=	emulators
MASTER_SITES=	http://www.opencores.org/projects.cgi/web/or1k/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opencores.org/projects.cgi/web/or1k/architectural_simulator
COMMENT=	OpenRISC emulator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--target=or32

.include "../../mk/bsd.pkg.mk"
