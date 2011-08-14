# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:23 obache Exp $

DISTNAME=	MooseX-Traits-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Traits/
COMMENT=	Automatically apply roles at object creation time
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-MOP>=0.84:../../devel/p5-Class-MOP
DEPENDS+=	p5-Moose>=0.84:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Traits/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
