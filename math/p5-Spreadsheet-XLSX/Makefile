# $NetBSD: Makefile,v 1.2 2009/08/30 00:35:15 seb Exp $
#

DISTNAME=	Spreadsheet-XLSX-0.1
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-XLSX/
COMMENT=	Perl 5 module to read MS Excel 2007 files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/XLSX/.packlist

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
