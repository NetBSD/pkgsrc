# $NetBSD: Makefile,v 1.9 2019/06/30 20:14:57 nia Exp $
#

DISTNAME=		Env-Path-0.19
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Env/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Env-Path
COMMENT=		Advanced operations on path variables
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Env/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
