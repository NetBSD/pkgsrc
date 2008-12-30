# $NetBSD: Makefile,v 1.18 2008/12/30 01:18:36 adrianp Exp $

DISTNAME=	dircproxy-1.2.0-beta2
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://dircproxy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://code.google.com/p/dircproxy/
COMMENT=	Detachable internet relay chat proxy server (devel version)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run

.include "options.mk"

CONFLICTS=		dircproxy<=1.1.0

REPLACE_PERL+=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR:Q}/dircproxyrc.sample \
			${PKG_SYSCONFDIR:Q}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
