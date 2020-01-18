# $NetBSD: Makefile,v 1.33 2020/01/18 21:48:48 jperkin Exp $

DISTNAME=	dircproxy-1.2.0-beta2
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	12
CATEGORIES=	chat
MASTER_SITES=	http://dircproxy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/w8tvi/dircproxy
COMMENT=	Detachable internet relay chat proxy server (devel version)

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run

.include "options.mk"

CONFLICTS=		dircproxy<=1.1.0

REPLACE_PERL+=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR}/dircproxyrc.sample \
			${PKG_SYSCONFDIR}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
