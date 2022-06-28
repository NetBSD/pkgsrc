# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:21 wiz Exp $

DISTNAME=	PPI-HTML-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPI-HTML
COMMENT=	Perl 5 module to generate syntax-hightlighted HTML for Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPI/HTML/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

DEPENDS+=	p5-CSS-Tiny>=1.10:../../www/p5-CSS-Tiny
DEPENDS+=	p5-PPI>=0.990:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util>=0.05:../../devel/p5-Params-Util

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
