# $NetBSD: Makefile,v 1.28 2023/07/06 09:38:17 wiz Exp $

DISTNAME=	Unicode-Map8-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-Map8
COMMENT=	Perl5 module providing mapping tables between charsets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unicode-String>=2.0:../../converters/p5-Unicode-String

PERL5_PACKLIST=		auto/Unicode/Map8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
