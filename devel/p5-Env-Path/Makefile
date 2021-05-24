# $NetBSD: Makefile,v 1.12 2021/05/24 19:50:35 wiz Exp $
#

DISTNAME=		Env-Path-0.19
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Env/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Env-Path
COMMENT=		Advanced operations on path variables
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Env/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
