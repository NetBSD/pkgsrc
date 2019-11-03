# $NetBSD: Makefile,v 1.9 2019/11/03 19:24:33 rillig Exp $

DISTNAME=	or1ksim-0.2.0rc2
PKGREVISION=	1
CATEGORIES=	emulators
#MASTER_SITES=	http://www.opencores.org/projects.cgi/web/or1k/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://opencores.org/or1k/Or1ksim
HOMEPAGE=	https://github.com/openrisc/or1ksim
COMMENT=	OpenRISC emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--target=or32

# rl_event_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
