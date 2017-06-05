# $NetBSD: Makefile,v 1.43 2017/06/05 14:23:16 ryoon Exp $

DISTNAME=	Module-ScanDeps-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/ScanDeps/.packlist

REPLACE_PERL+=	script/scandeps.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
