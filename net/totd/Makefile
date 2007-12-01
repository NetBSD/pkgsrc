# $NetBSD: Makefile,v 1.27 2007/12/01 13:23:14 rillig Exp $
#

DISTNAME=	totd-1.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/totd/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/software/totd.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_OPTIONS_VAR=		PKG_OPTIONS.totd
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

INSTALLATION_DIRS_FROM_PLIST=	yes
BUILDLINK_TRANSFORM+=		rm:-Werror

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/totd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/totd.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
