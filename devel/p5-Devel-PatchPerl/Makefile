# $NetBSD: Makefile,v 1.34 2020/06/06 14:04:49 wen Exp $

DISTNAME=	Devel-PatchPerl-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-PatchPerl
COMMENT=	Perl 5 module to patch a perl source tree
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-pushd>=1.00:../../devel/p5-File-pushd
DEPENDS+=	p5-Module-Pluggable>=5.1:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/PatchPerl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
