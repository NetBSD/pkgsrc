# $NetBSD: Makefile,v 1.17 2011/08/14 12:26:44 obache Exp $

DISTNAME=	Test-Unit-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tun
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Test-Unit
COMMENT=	Perl extension module for Unit Tests

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Inner-[0-9]*:../../devel/p5-Class-Inner
DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error

PERL5_PACKLIST=		auto/Test/Unit/.packlist

REPLACE_PERL+=	*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
