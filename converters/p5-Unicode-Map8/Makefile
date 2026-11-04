# $NetBSD: Makefile,v 1.33 2026/11/04 06:36:02 wiz Exp $

DISTNAME=	Unicode-Map8-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-Map8
COMMENT=	Perl5 module providing mapping tables between charsets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unicode-String>=2.0:../../converters/p5-Unicode-String

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
