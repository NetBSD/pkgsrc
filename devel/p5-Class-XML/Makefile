# $NetBSD: Makefile,v 1.1.1.1 2007/08/03 06:57:01 seb Exp $
#

DISTNAME=	Class-XML-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-XML/
COMMENT=	Perl 5 module providing a simple XML abstraction

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-Accessor>=0.19:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-XML-XPath>=1.13:../../textproc/p5-XML-XPath

PERL5_PACKLIST=	auto/Class/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
