# $NetBSD: Makefile,v 1.4 2011/12/19 16:09:22 wiz Exp $
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
USE_GNU_READLINE=	YES # rl_event_hook

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
