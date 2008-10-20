# $NetBSD: Makefile,v 1.1.1.1 2008/10/20 22:41:15 he Exp $

DISTNAME=	Excel-Template-0.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Excel-Template/
COMMENT=	Perl module for templating Excel files

DEPENDS+=	p5-IO>=0.01:../../devel/p5-IO
DEPENDS+=	p5-Spreadsheet-WriteExcel>=0.42:../../math/p5-Spreadsheet-WriteExcel
DEPENDS+=	p5-XML-Parser>=0.01:../../textproc/p5-XML-Parser

BUILD_DEPENDS+=	p5-Test-Deep>=0.095:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Excel/Template/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
