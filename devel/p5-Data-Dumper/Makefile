# $NetBSD: Makefile,v 1.14 2001/02/16 14:38:47 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp

DISTNAME=	Data-Dumper-2.101
PKGNAME=	p5-Data-Dumper-2.101
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Data-Dumper/Dumper.html
COMMENT=	perl5 module for stringified perl data structures

# Some perl packages install their own versions of this module.
# Can't simply define USE_PERL5.
DEPENDS+=	perl-{5.0*,5.6.0nb[12],base-5.[6-9]*}:../../lang/perl5-base

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Data/Dumper/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
