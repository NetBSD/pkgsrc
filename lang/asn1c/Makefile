# $NetBSD: Makefile,v 1.1 2013/10/26 14:44:12 sno Exp $
#

DISTNAME=		asn1c-0.9.24
CATEGORIES=		lang
MASTER_SITES=		http://lionet.info/soft/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lionet.info/asn1c/
COMMENT=		Free, open source compiler of ASN.1 specifications into C source code
LICENSE=		2-clause-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		autoconf gmake perl:run
GNU_CONFIGURE=		yes

REPLACE_PERL+=		examples/crfc2asn1.pl
REPLACE_PERL+=		examples/clyx2asn1.pl

.include "../../mk/bsd.pkg.mk"
