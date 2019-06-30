# $NetBSD: Makefile,v 1.16 2019/06/30 20:15:21 nia Exp $

DISTNAME=		Module-Runtime-0.016
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Module-Runtime
COMMENT=		Deal with runtime handling of Perl modules
LICENSE=		${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Runtime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
