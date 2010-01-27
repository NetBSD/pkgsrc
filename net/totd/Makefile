# $NetBSD: Makefile,v 1.30 2010/01/27 17:33:43 joerg Exp $
#

DISTNAME=	totd-1.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/totd/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/software/totd.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_OPTIONS_VAR=		PKG_OPTIONS.totd
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

BUILDLINK_TRANSFORM+=		rm:-Werror

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/totd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/totd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/totd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${DESTDIR}${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
