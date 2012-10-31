# $NetBSD: Makefile,v 1.6 2012/10/31 11:18:07 asau Exp $

DISTNAME=	ExtUtils-ModuleMaker-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ModuleMaker/
COMMENT=	Perl extension for creating modules (better than h2xs)
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-File-Save-Home>=0.03:../../devel/p5-File-Save-Home

PERL5_PACKLIST=		auto/ExtUtils/ModuleMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
