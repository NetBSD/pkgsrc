# $NetBSD: Makefile,v 1.21 2023/07/06 09:39:49 wiz Exp $
#

DISTNAME=	Parse-CPAN-Packages-2.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-CPAN-Packages
COMMENT=	Perl 5 module to parse 02packages.details.txt.gz
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/CPAN/Packages/.packlist

DEPENDS+=	p5-Archive-Peek-[0-9]*:../../archivers/p5-Archive-Peek
DEPENDS+=	p5-CPAN-DistnameInfo-[0-9]*:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

TOOL_DEPENDS+=	p5-Test-InDistDir-[0-9]*:../../devel/p5-Test-InDistDir
# for make test
TOOL_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TOOL_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
TOOL_DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
