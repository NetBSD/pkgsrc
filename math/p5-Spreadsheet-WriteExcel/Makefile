# $NetBSD: Makefile,v 1.1.1.1 2002/03/19 15:03:31 mjl Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-*:../../devel/p5-Parse-RecDescent

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Spreadsheet/WriteExcel/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
