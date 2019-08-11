# $NetBSD: Makefile,v 1.4 2019/08/11 13:20:33 wiz Exp $

DISTNAME=		Test-More-UTF8-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-More-UTF8
COMMENT=		Enhancing Test::More for UTF8-based projects
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/More/UTF8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
