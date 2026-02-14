# $NetBSD: Makefile,v 1.20 2026/02/14 08:36:36 wiz Exp $

DISTNAME=	tre-0.8.0
CATEGORIES=	devel
#MASTER_SITES=	https://laurikari.net/tre/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	https://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library
LICENSE=	modified-bsd

# both install bin/agrep (approx. grep)
CONFLICTS+=	glimpse-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-system-abi

# This contains some annoying legacy code that only includes <alloca.h>
# when a non-GNU compiler is used, resulting in failures with recent gcc
# (and probably clang too).
#
# Be safe, use an alloc function that returns NULL on failure.
CONFIGURE_ARGS+=	--without-alloca

INSTALLATION_DIRS+=	share/doc/tre

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tre-api.html ${DESTDIR}${PREFIX}/share/doc/tre/
	${INSTALL_DATA} ${WRKSRC}/doc/tre-syntax.html ${DESTDIR}${PREFIX}/share/doc/tre/

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
