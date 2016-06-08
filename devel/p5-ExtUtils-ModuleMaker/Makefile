# $NetBSD: Makefile,v 1.14 2016/06/08 19:22:54 wiz Exp $

DISTNAME=	ExtUtils-ModuleMaker-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ModuleMaker/
COMMENT=	Perl extension for creating modules (better than h2xs)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Save-Home>=0.03:../../devel/p5-File-Save-Home
BUILD_DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture

PERL5_PACKLIST=		auto/ExtUtils/ModuleMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
