# $NetBSD: Makefile,v 1.6 2011/08/14 13:38:24 obache Exp $
#

DISTNAME=	Spreadsheet-XLSX-0.13-withoutworldwriteables
PKGNAME=	p5-${DISTNAME:S/-withoutworldwriteables//}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-XLSX/
COMMENT=	Perl 5 module to read MS Excel 2007 files

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/p5-//}
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/XLSX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
