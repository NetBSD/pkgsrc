# $NetBSD: Makefile,v 1.10 2004/03/10 18:51:13 wiz Exp $
#

DISTNAME=	NewsCache-0.99.22p1
PKGNAME=	${DISTNAME:S/p/.0./}
CATEGORIES=	news
MASTER_SITES=	http://www.hstraub.at/linux/downloads/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://members.aon.at/hstraub/linux/newscache/
COMMENT=	Free cache server for USENET News

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
INFO_FILES=	NewsCache.info

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

CONF_FILES=	${PREFIX}/share/examples/NewsCache/newscache.conf \
		${PKG_SYSCONFDIR}/newscache.conf

post-extract:
	${MV} ${WRKSRC}/etc/newscache.conf-dist ${WRKSRC}/etc/newscache.conf

.include "../../mk/bsd.pkg.mk"
