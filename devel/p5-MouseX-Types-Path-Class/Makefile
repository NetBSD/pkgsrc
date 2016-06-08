# $NetBSD: Makefile,v 1.5 2016/06/08 19:23:19 wiz Exp $
#

DISTNAME=		MouseX-Types-Path-Class-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MouseX/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MouseX-Types-Path-Class/
COMMENT=		Path::Class type library for Mouse
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MouseX/Types/Path/Class/.packlist

DEPENDS+=		p5-Mouse>=0.39:../../devel/p5-Mouse
DEPENDS+=		p5-MouseX-Types>=0.02:../../devel/p5-MouseX-Types
DEPENDS+=		p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

# XXX recommends 'MouseX::Getopt' => '0.2200';

BUILD_DEPENDS+=		p5-Test-UseAllModules-[0-9]*:../../devel/p5-Test-UseAllModules


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
