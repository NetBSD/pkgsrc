# $NetBSD: Makefile,v 1.2 2013/05/31 12:40:17 wiz Exp $
#

DISTNAME=		Env-Path-0.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Env/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Env-Path/
COMMENT=		Advanced operations on path variables
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Env/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
