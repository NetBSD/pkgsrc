# $NetBSD: Makefile,v 1.22 2014/10/09 14:06:26 wiz Exp $
#

DISTNAME=	Safe-Hole-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Safe-Hole/
COMMENT=	Exec subs in the original package from within a Safe object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Safe/Hole/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
