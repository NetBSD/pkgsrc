# $NetBSD: Makefile,v 1.4 2003/09/02 12:45:26 seb Exp $

DISTNAME=	dircproxy-1.0.5
CATEGORIES=	chat
MASTER_SITES=	http://www.dircproxy.net/download/stable/

MAINTAINER=	sb125499@ohiou.edu
HOMEPAGE=	http://www.dircproxy.net/
COMMENT=	Detachable internet relay chat proxy server

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		YES
USE_PKGINSTALL=		YES

REPLACE_PERL=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR}/dircproxyrc ${PKG_SYSCONFDIR}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
