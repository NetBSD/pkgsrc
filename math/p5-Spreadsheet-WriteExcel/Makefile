# $NetBSD: Makefile,v 1.39 2022/06/28 11:34:43 wiz Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-2.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Spreadsheet-WriteExcel
COMMENT=	Create Excel data files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-OLE-Storage_Lite>=0.19:../../devel/p5-OLE-Storage_Lite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
