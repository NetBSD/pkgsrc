# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:49 obache Exp $

DISTNAME=	namespace-autoclean-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-autoclean/
COMMENT=	Keep imports out of your namespace
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-Class-MOP>=0.80:../../devel/p5-Class-MOP
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/namespace/autoclean/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
