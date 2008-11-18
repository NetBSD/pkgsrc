# $NetBSD: Makefile,v 1.14 2008/11/18 06:03:58 he Exp $
#

DISTNAME=	Spreadsheet-ParseExcel-0.41
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-ParseExcel/
COMMENT=	Perl module to get information from an Excel file

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-OLE-Storage_Lite>=0.08:../../devel/p5-OLE-Storage_Lite

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/Spreadsheet/ParseExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
