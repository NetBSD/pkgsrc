# $NetBSD: Makefile,v 1.10 2022/06/28 11:34:09 wiz Exp $
#

DISTNAME=		asn1c-0.9.24
PKGREVISION=		8
CATEGORIES=		lang
MASTER_SITES=		http://lionet.info/soft/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lionet.info/asn1c/
COMMENT=		Free, open source compiler of ASN.1 specifications into C source code
LICENSE=		2-clause-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		autoconf gmake perl:run
GNU_CONFIGURE=		yes

REPLACE_PERL+=		examples/crfc2asn1.pl
REPLACE_PERL+=		examples/clyx2asn1.pl

.include "../../mk/bsd.pkg.mk"
