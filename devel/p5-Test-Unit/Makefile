# $NetBSD: Makefile,v 1.6 2004/11/30 12:08:52 wiz Exp $

DISTNAME=	Test-Unit-0.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tun
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Test-Unit
COMMENT=	Perl extension module for Unit Tests

DEPENDS+=	p5-Class-Inner-[0-9]*:../../devel/p5-Class-Inner
DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Unit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
