# $NetBSD: Makefile,v 1.27 2022/06/28 11:36:34 wiz Exp $
#

DISTNAME=	Text-RewriteRules-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-RewriteRules
COMMENT=	Perl 5 module to rewrite text using regexp-based rules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/RewriteRules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
