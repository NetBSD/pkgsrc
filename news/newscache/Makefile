# $NetBSD: Makefile,v 1.6 2003/06/02 01:17:36 jschauma Exp $
#

DISTNAME=	NewsCache-0.99.17
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.infosys.tuwien.ac.at/NewsCache/download/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.infosys.tuwien.ac.at/NewsCache/
COMMENT=	Free cache server for USENET News

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

CONF_FILES=	${PREFIX}/share/examples/NewsCache/newscache.conf \
		${PKG_SYSCONFDIR}/newscache.conf

post-extract:
	${MV} ${WRKSRC}/etc/newscache.conf-dist ${WRKSRC}/etc/newscache.conf

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
