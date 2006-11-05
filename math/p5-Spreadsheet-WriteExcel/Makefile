# $NetBSD: Makefile,v 1.13 2006/11/05 02:27:37 obache Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-2.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-WriteExcel/
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=		auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
