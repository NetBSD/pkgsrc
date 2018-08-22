# $NetBSD: Makefile,v 1.23 2018/08/22 09:44:57 wiz Exp $

DISTNAME=	namespace-autoclean-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-autoclean/
COMMENT=	Keep imports out of your namespace
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean
DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

# used by some tests but would introduce cyclic dependency
#BUILD_DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/namespace/autoclean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
