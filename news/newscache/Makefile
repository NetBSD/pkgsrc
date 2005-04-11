# $NetBSD: Makefile,v 1.14 2005/04/11 21:47:03 tv Exp $
#

DISTNAME=	NewsCache-0.99.22p1
PKGNAME=	${DISTNAME:S/p/.0./}
CATEGORIES=	news
MASTER_SITES=	http://www.hstraub.at/linux/downloads/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxhacker.at/newscache/
COMMENT=	Free cache server for USENET News

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_PKGINSTALL=	YES
INFO_FILES=	NewsCache.info

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

CONF_FILES=	${PREFIX}/share/examples/NewsCache/newscache.conf \
		${PKG_SYSCONFDIR}/newscache.conf

post-extract:
	${MV} ${WRKSRC}/etc/newscache.conf-dist ${WRKSRC}/etc/newscache.conf

.include "../../mk/bsd.pkg.mk"
