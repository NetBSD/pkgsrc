# $NetBSD: Makefile,v 1.30 2015/08/06 08:26:17 wiz Exp $

DISTNAME=	Variable-Magic-0.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Variable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Variable-Magic/
COMMENT=	Perl 5 module to associate user-defined magic to variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Variable/Magic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
