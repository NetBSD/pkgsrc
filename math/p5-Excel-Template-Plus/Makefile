# $NetBSD: Makefile,v 1.17 2019/08/11 13:21:45 wiz Exp $

DISTNAME=	Excel-Template-Plus-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Excel-Template-Plus
COMMENT=	Extension to the Excel::Template module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Excel-Template-[0-9]*:../../math/p5-Excel-Template
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Moose>=0.18:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Param>=0.01:../../devel/p5-MooseX-Param
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Excel/Template/Plus/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
