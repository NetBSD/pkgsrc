# $NetBSD: Makefile,v 1.35 2025/07/04 08:46:34 wiz Exp $

DISTNAME=	Safe-Hole-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Safe-Hole
COMMENT=	Exec subs in the original package from within a Safe object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Safe/Hole/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
