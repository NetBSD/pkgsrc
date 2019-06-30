# $NetBSD: Makefile,v 1.23 2019/06/30 20:15:21 nia Exp $

DISTNAME=	Module-Starter-1.75
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Starter
COMMENT=	Perl 5 module acting as a simple starter kit for any module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
