# $NetBSD: Makefile,v 1.18 2017/09/06 09:03:01 wiz Exp $

DISTNAME=	tre-0.8.0
CATEGORIES=	devel
MASTER_SITES=	https://laurikari.net/tre/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library
LICENSE=	modified-bsd

# both install bin/agrep (approx. grep)
CONFLICTS+=	glimpse-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-system-abi

INSTALLATION_DIRS+=	share/doc/tre

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tre-api.html ${DESTDIR}${PREFIX}/share/doc/tre/
	${INSTALL_DATA} ${WRKSRC}/doc/tre-syntax.html ${DESTDIR}${PREFIX}/share/doc/tre/

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
