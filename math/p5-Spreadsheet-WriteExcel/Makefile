# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:26 jschauma Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-0.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-File-Temp-*:../../devel/p5-File-Temp

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
