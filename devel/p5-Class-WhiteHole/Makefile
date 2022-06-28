# $NetBSD: Makefile,v 1.25 2022/06/28 11:32:05 wiz Exp $

DISTNAME=	Class-WhiteHole-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-WhiteHole
COMMENT=	Perl5 module to ensure error on unhandled method calls
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
