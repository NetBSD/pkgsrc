# $NetBSD: Makefile,v 1.26 2023/07/06 09:38:49 wiz Exp $

DISTNAME=	Class-WhiteHole-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-WhiteHole
COMMENT=	Perl5 module to ensure error on unhandled method calls
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
