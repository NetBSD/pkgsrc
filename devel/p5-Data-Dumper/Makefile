# $NetBSD: Makefile,v 1.12 2000/08/27 21:05:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp

DISTNAME=	Data-Dumper-2.101
PKGNAME=	p5-Data-Dumper-2.101
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Data-Dumper/Dumper.html

CONFLICTS=	perl-5.6.0	# needs perl>5.6.0 or perl-5.00*

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Data/Dumper/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
