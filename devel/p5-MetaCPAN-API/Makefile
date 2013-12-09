# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:45 obache Exp $

DISTNAME=	MetaCPAN-API-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/X/XS/XSAWYERX/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MetaCPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MetaCPAN-API/
COMMENT=	Comprehensive, DWIM-featured API to MetaCPAN for Perl5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	{perl>=5.13.9,p5-HTTP-Tiny-[0-9]*}:../../www/p5-HTTP-Tiny
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-TinyMocker-[0-9]*:../../devel/p5-Test-TinyMocker

PERL5_PACKLIST=		auto/MetaCPAN/API/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
