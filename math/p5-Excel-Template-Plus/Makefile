# $NetBSD: Makefile,v 1.1.1.1 2008/10/20 22:57:45 he Exp $

DISTNAME=	Excel-Template-Plus-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Excel-Template-Plus/
COMMENT=	An extension to the Excel::Template module

DEPENDS+=	p5-Excel-Template>=0:../../math/p5-Excel-Template
DEPENDS+=	p5-IO-String>=0:../../devel/p5-IO-String
DEPENDS+=	p5-Moose>=0.18:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Param>=0.01:../../devel/p5-MooseX-Param
DEPENDS+=	p5-Spreadsheet-ParseExcel>=0:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Excel/Template/Plus/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
