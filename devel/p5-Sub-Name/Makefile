# $NetBSD: Makefile,v 1.23 2019/06/30 20:15:45 nia Exp $

DISTNAME=	Sub-Name-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Name
COMMENT=	Perl 5 module to (re)name a sub
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Devel-CheckBin-[0-9]*:../../devel/p5-Devel-CheckBin

PERL5_PACKLIST=	auto/Sub/Name/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
