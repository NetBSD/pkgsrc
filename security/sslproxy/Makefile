# $NetBSD: Makefile,v 1.9 2017/09/04 18:08:28 wiz Exp $

DISTNAME=	sslproxy-1.1.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sslproxy/1.1.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/sslproxy/
COMMENT=	Small SSL proxy
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ssl_proxy
INSTALLATION_DIRS=	bin ${DOCDIR}

MAKE_ENV.SunOS+=	LDLIBS="-lsocket -lnsl"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssl_proxy ${DESTDIR}${PREFIX}/bin/ssl_proxy
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
