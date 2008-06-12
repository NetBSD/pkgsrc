# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:16 joerg Exp $

DISTNAME=	dircproxy-1.0.5
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.netsplit.com/pub/dircproxy/stable/ \
		http://dircproxy.securiweb.net/pub/1.0/

MAINTAINER=	sb125499@ohiou.edu
HOMEPAGE=	http://dircproxy.securiweb.net/
COMMENT=	Detachable internet relay chat proxy server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run

CONFLICTS=		dircproxy-1.1.[0-9]*

REPLACE_PERL=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR}/dircproxyrc ${PKG_SYSCONFDIR}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
