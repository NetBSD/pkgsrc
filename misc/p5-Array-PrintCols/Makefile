# $NetBSD: Makefile,v 1.10 2001/04/20 23:56:12 jtb Exp $
# FreeBSD Id: Makefile,v 1.9 1997/09/14 02:54:03 jfitz Exp
#

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Array-PrintCols/PrintCols.html
COMMENT=		perl5 module to print arrays of elements in sorted columns

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Array/PrintCols/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
