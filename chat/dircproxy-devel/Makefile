# $NetBSD: Makefile,v 1.6 2006/02/19 15:47:35 adrianp Exp $

DISTNAME=	dircproxy-1.2.0-beta
PKGNAME=	${DISTNAME:S/-beta//}
CATEGORIES=	chat
MASTER_SITES=	http://dircproxy.securiweb.net/pub/1.2/
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://dircproxy.securiweb.net/
COMMENT=	Detachable internet relay chat proxy server (devel version)

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run

.include "options.mk"

CONFLICTS=		dircproxy-1.[0-1].[0-9]*

REPLACE_PERL+=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR:Q}/dircproxyrc.sample \
			${PKG_SYSCONFDIR:Q}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
