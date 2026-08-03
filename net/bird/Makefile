# $NetBSD: Makefile,v 1.17 2026/08/03 08:26:27 adam Exp $

DISTNAME=	bird-3.3.2
CATEGORIES=	net
MASTER_SITES=	https://bird.nic.cz/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bird.nic.cz/
COMMENT=	The BIRD Internet Routing Daemon
LICENSE=	gnu-gpl-v2

# Has hardcoded BSD/Linux support.
NOT_FOR_PLATFORM=	Darwin-*-* SunOS-*-*

SUPERSEDES+=		bird6-[0-9]*

BUILD_DEFS+=		VARBASE

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake flex bison gm4
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

RCD_SCRIPTS+=		bird

EGDIR=			${PREFIX}/share/examples/bird
ALL_ENV+=		EGDIR=${EGDIR}
CONF_FILES=		${EGDIR}/bird.conf ${PKG_SYSCONFDIR}/bird.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
