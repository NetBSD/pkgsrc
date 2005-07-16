# $NetBSD: Makefile,v 1.11 2005/07/16 01:19:07 jlam Exp $

DISTNAME=	dircproxy-1.0.5
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.securiweb.net/pub/oss/dircproxy/1.0/

MAINTAINER=	sb125499@ohiou.edu
HOMEPAGE=	http://dircproxy.securiweb.net/
COMMENT=	Detachable internet relay chat proxy server

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run
USE_PKGINSTALL=		YES

CONFLICTS=		dircproxy-1.1.[0-9]*

REPLACE_PERL=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR}/dircproxyrc ${PKG_SYSCONFDIR}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
