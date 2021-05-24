# $NetBSD: Makefile,v 1.19 2021/05/24 19:50:19 wiz Exp $

DISTNAME=	Class-Unload-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Unload
COMMENT=	Perl 5 module to unload a class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Class/Unload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
