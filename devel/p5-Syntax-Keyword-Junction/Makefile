# $NetBSD: Makefile,v 1.21 2023/07/06 09:40:04 wiz Exp $

DISTNAME=	Syntax-Keyword-Junction-0.003008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Syntax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Syntax-Keyword-Junction
COMMENT=	Perl5 module to provide keywords for any, all, none, or one
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001006:../../devel/p5-Sub-Exporter-Progressive
DEPENDS+=	p5-syntax-[0-9]*:../../devel/p5-syntax
# for make test
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Syntax/Keyword/Junction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
