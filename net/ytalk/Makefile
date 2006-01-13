# $NetBSD: Makefile,v 1.11.16.1 2006/01/13 00:54:38 salo Exp $

DISTNAME=       ytalk-3.3.0
CATEGORIES=	net
MASTER_SITES=   http://www.impul.se/ytalk/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.impul.se/ytalk/index.php
COMMENT=	Multi-user replacement for UNIX talk

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
