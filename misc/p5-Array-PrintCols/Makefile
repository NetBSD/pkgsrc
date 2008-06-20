# $NetBSD: Makefile,v 1.24 2008/06/20 01:09:26 joerg Exp $

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5arp
PKGREVISION=		2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Array-PrintCols/PrintCols.html
COMMENT=		Perl5 module to print arrays of elements in sorted columns

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Array/PrintCols/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
