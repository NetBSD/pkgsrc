# $NetBSD: Makefile,v 1.2 2023/07/06 09:39:08 wiz Exp $

DISTNAME=	Feature-Compat-Try-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Feature::Compat::Try
COMMENT=	Perl module to make try/catch syntax available
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Feature/Compat/Try/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
