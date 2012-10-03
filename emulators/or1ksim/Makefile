# $NetBSD: Makefile,v 1.5 2012/10/03 12:55:16 asau Exp $
#

DISTNAME=	or1ksim-0.2.0rc2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.opencores.org/projects.cgi/web/or1k/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opencores.org/projects.cgi/web/or1k/architectural_simulator
COMMENT=	OpenRISC emulator

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--target=or32
USE_GNU_READLINE=	YES # rl_event_hook

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
