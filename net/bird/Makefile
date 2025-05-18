# $NetBSD: Makefile,v 1.6 2025/05/18 02:10:49 markd Exp $
# used by net/bird/Makefile
# used by net/bird6/Makefile

DISTNAME=	bird-2.17.1
CATEGORIES=	net
MASTER_SITES=	https://bird.network.cz/download/
MASTER_SITES+=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bird.network.cz/
COMMENT=	The BIRD Internet Routing Daemon
LICENSE=	gnu-gpl-v2

# Has hardcoded BSD/Linux support.
NOT_FOR_PLATFORM=	SunOS-*-*

BUILD_DEFS+=		VARBASE

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake flex bison gm4

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

RCD_SCRIPTS+=		bird

EGDIR=			${PREFIX}/share/examples/bird
ALL_ENV+=		EGDIR=${EGDIR}
CONF_FILES=		${EGDIR}/bird.conf ${PKG_SYSCONFDIR}/bird.conf

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
