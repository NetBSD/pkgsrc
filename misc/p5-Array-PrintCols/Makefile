# $NetBSD: Makefile,v 1.12 2001/11/26 06:50:07 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/09/14 02:54:03 jfitz Exp
#

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5arp
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Array-PrintCols/PrintCols.html
COMMENT=		perl5 module to print arrays of elements in sorted columns

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Array/PrintCols/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
