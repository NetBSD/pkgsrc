# $NetBSD: Makefile,v 1.31 2011/04/15 08:34:00 obache Exp $
#

DISTNAME=	totd-1.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/totd/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/software/totd.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_FEATURES+=	inet6

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

BUILDLINK_TRANSFORM+=		rm:-Werror

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/totd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/totd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/totd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${DESTDIR}${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
