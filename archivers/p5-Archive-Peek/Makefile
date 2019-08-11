# $NetBSD: Makefile,v 1.13 2019/08/11 13:17:51 wiz Exp $

DISTNAME=	Archive-Peek-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Peek
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
