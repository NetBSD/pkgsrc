# $NetBSD: Makefile,v 1.28 2023/07/06 09:38:47 wiz Exp $

DISTNAME=	Class-Method-Modifiers-2.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Method-Modifiers
COMMENT=	Perl module providing Moose-like method modifiers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Method/Modifiers/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
