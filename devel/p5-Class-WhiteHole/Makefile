# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:14 joerg Exp $
#

DISTNAME=		Class-WhiteHole-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cwh
PKGREVISION=		2
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-WhiteHole/
COMMENT=		Perl5 module to ensure error on unhandled method calls

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
