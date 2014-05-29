# $NetBSD: Makefile,v 1.9 2014/05/29 23:35:50 wiz Exp $

DISTNAME=	Devel-PatchPerl-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-PatchPerl/
COMMENT=	Perl 5 module to patch a perl source tree
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-pushd>=1.00:../../devel/p5-File-pushd

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/PatchPerl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
