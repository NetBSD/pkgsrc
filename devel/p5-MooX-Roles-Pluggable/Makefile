# $NetBSD: Makefile,v 1.7 2017/06/05 14:23:18 ryoon Exp $

DISTNAME=	MooX-Roles-Pluggable-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rehsack/MooX-Roles-Pluggable//
COMMENT=	Moo eXtension for pluggable roles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/MooX/Roles/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
