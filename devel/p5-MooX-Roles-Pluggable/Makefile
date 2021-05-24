# $NetBSD: Makefile,v 1.12 2021/05/24 19:51:07 wiz Exp $

DISTNAME=	MooX-Roles-Pluggable-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Roles-Pluggable
COMMENT=	Moo eXtension for pluggable roles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/MooX/Roles/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
