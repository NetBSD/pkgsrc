# $NetBSD: Makefile,v 1.2 2013/05/31 12:41:57 wiz Exp $
#

DISTNAME=		polarssl-1.2.0-gpl
PKGNAME=		${DISTNAME:-gpl=}
PKGREVISION=		1
CATEGORIES=		security devel
MASTER_SITES=		http://polarssl.org/code/releases/
EXTRACT_SUFX=		.tgz
FETCH_USING=		curl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://polarssl.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl
REPLACE_PERL=		tests/scripts/*.pl
USE_LANGUAGES=		c
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
