# $NetBSD: Makefile,v 1.12 2026/11/27 08:14:32 wiz Exp $
#
DISTNAME=	asn1c-0.9.29
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lionet.info/asn1c/
COMMENT=	Free, open source compiler of ASN.1 specifications into C source code
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf automake autoconf flex gmake perl:run
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

REPLACE_PERL+=	examples/crfc2asn1.pl
REPLACE_PERL+=	libasn1parser/expr-h.pl
REPLACE_PERL+=	tests/tests-asn1c-compiler/check-parsing-log2diff.pl

pre-configure:
	cd ${WRKSRC} && autoreconf -iv

.include "../../mk/bsd.pkg.mk"
