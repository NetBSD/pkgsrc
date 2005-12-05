# $NetBSD: Makefile,v 1.4 2005/12/05 23:55:02 rillig Exp $

DISTNAME=	dircproxy-1.1.0
CATEGORIES=	chat
MASTER_SITES=	http://www.securiweb.net/pub/oss/dircproxy/1.1/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://dircproxy.securiweb.net/
COMMENT=	Detachable internet relay chat proxy server

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run
USE_PKGINSTALL=		YES

CONFLICTS=		dircproxy-1.0.[0-9]*

REPLACE_PERL=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR}/dircproxyrc ${PKG_SYSCONFDIR}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
