# $NetBSD: Makefile,v 1.17 2004/04/27 02:24:08 snj Exp $
# FreeBSD Id: Makefile,v 1.9 1997/09/14 02:54:03 jfitz Exp
#

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5arp
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Array-PrintCols/PrintCols.html
COMMENT=		Perl5 module to print arrays of elements in sorted columns

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Array/PrintCols/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
