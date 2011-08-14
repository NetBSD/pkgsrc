# $NetBSD: Makefile,v 1.28 2011/08/14 13:45:14 obache Exp $

DISTNAME=		Array-PrintCols-2.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5arp
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Array-PrintCols/
COMMENT=		Perl5 module to print arrays of elements in sorted columns

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Array/PrintCols/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
