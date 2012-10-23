# $NetBSD: Makefile,v 1.3 2012/10/23 18:16:59 asau Exp $

DISTNAME=	sslproxy-1.0.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sslproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sslproxy/
COMMENT=	Small SSL proxy

EXTRACT_SUFX=		.tgz

USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ssl_proxy
INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssl_proxy ${DESTDIR}${PREFIX}/bin/ssl_proxy
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
