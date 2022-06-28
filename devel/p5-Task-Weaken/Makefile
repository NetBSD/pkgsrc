# $NetBSD: Makefile,v 1.26 2022/06/28 11:33:17 wiz Exp $

DISTNAME=	Task-Weaken-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Task-Weaken
COMMENT=	Perl 5 module to ensure that a platform has weaken support
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/Task/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
