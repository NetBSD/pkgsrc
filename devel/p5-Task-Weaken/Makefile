# $NetBSD: Makefile,v 1.23 2019/11/03 10:16:04 rillig Exp $

DISTNAME=	Task-Weaken-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
