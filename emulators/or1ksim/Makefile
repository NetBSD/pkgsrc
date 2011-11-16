# $NetBSD: Makefile,v 1.3 2011/11/16 08:23:48 sbd Exp $
#

DISTNAME=	or1ksim-0.2.0rc2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.opencores.org/projects.cgi/web/or1k/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opencores.org/projects.cgi/web/or1k/architectural_simulator
COMMENT=	OpenRISC emulator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--target=or32

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
