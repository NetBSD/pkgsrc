# $NetBSD: Makefile,v 1.19 2005/03/24 21:12:58 wiz Exp $

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5arp
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Array-PrintCols/PrintCols.html
COMMENT=		Perl5 module to print arrays of elements in sorted columns

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Array/PrintCols/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
