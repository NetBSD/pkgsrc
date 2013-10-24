# $NetBSD: Makefile,v 1.5 2013/10/24 10:39:24 jperkin Exp $

DISTNAME=	sslproxy-1.1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sslproxy/1.1.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sslproxy/
COMMENT=	Small SSL proxy
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/ssl_proxy
INSTALLATION_DIRS=	bin ${DOCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LDLIBS="-lsocket -lnsl"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssl_proxy ${DESTDIR}${PREFIX}/bin/ssl_proxy
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
