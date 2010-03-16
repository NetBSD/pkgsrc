# $NetBSD: Makefile,v 1.5 2010/03/16 22:41:56 sno Exp $
#

DISTNAME=	Spreadsheet-Read-0.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-Read/
COMMENT=	Perl 5 module to read the data from a spreadsheet

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/Read/.packlist
MAKE_ENV+=		AUTOMATED_TESTING=1

# This is useless but placate check-interpreter.mk
REPLACE_PERL+=	Read.pm

DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.57:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-Text-CSV_XS>=0.72:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-Text-CSV>=1.16:../../textproc/p5-Text-CSV
DEPENDS+=	p5-Spreadsheet-XLSX>=0.12:../../math/p5-Spreadsheet-XLSX
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-File-Temp>=0.22:../../devel/p5-File-Temp
DEPENDS+=	p5-IO-stringy>=0:../../devel/p5-IO-stringy

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Simple>=0.94:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
