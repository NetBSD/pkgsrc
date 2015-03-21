# $NetBSD: Makefile,v 1.7 2015/03/21 19:39:44 jperkin Exp $
#

DISTNAME=		polarssl-1.2.12-gpl
PKGNAME=		${DISTNAME:-gpl=}
CATEGORIES=		security devel
MASTER_SITES=		https://polarssl.org/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://polarssl.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl
REPLACE_PERL=		tests/scripts/*.pl
USE_LANGUAGES=		c
TEST_TARGET=		check

MAKE_ENV+=		RANLIB=${RANLIB:Q}

.include "../../mk/bsd.pkg.mk"
