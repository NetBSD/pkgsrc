# $NetBSD: Makefile,v 1.1 2014/08/17 07:14:41 wen Exp $

DISTNAME=		Test-CleanNamespaces-0.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Roo/
COMMENT=		Check for uncleaned imports
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-File-Find-Rule-Perl>=0:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
DEPENDS+=	p5-Role-Tiny>=0:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Package-Stash-XS>=0:../../devel/p5-Package-Stash-XS

BUILD_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/Test/CleanNamespaces/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
