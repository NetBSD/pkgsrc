# $NetBSD: Makefile,v 1.10 2017/06/05 14:22:16 ryoon Exp $

DISTNAME=	Archive-Peek-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Peek/
COMMENT=	Perl5 module to peek into archives without extracting them
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class-[0-9]*:../../devel/p5-MooseX-Types-Path-Class

# for make test
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/Archive/Peek/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
