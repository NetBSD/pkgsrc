# $NetBSD: Makefile,v 1.1.1.1 2007/08/06 20:29:42 seb Exp $
#

DISTNAME=	Perl6-Export-Attrs-0.0.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl6-Export-Attrs/
COMMENT=	Perl 5 module implementing Perl 6 symbol export mechanism

DEPENDS+=	p5-Attribute-Handlers-[0-9]*:../../devel/p5-Attribute-Handlers
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Export/Attrs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
