# $NetBSD: Makefile,v 1.33 2017/06/05 14:24:12 ryoon Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-2.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-WriteExcel/
COMMENT=	Create Excel data files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-OLE-Storage_Lite>=0.19:../../devel/p5-OLE-Storage_Lite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
