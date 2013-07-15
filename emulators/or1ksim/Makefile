# $NetBSD: Makefile,v 1.6 2013/07/15 02:02:21 ryoon Exp $
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

# rl_event_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
