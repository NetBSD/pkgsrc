# $NetBSD: Makefile,v 1.3 2009/11/10 13:21:14 seb Exp $
#

DISTNAME=	Spreadsheet-Read-0.37
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

DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.49:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-Text-CSV_XS>=0.69:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-Text-CSV>=1.15:../../textproc/p5-Text-CSV
DEPENDS+=	p5-Spreadsheet-XLSX>=0.12:../../math/p5-Spreadsheet-XLSX
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Simple>=0.88:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
