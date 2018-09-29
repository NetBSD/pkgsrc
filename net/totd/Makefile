# $NetBSD: Makefile,v 1.34 2018/09/29 10:52:55 maya Exp $
#

DISTNAME=	totd-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fwdillema/}
GITHUB_PROJECT=	totd

MAINTAINER=	feico@dillema.net
HOMEPAGE=	https://github.com/fwdillema/totd
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

GNU_CONFIGURE=	yes
USE_FEATURES+=	inet6

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/totd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/totd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/totd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${DESTDIR}${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
