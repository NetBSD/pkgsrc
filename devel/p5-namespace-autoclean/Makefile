# $NetBSD: Makefile,v 1.9 2012/10/03 21:55:52 wiz Exp $

DISTNAME=	namespace-autoclean-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-autoclean/
COMMENT=	Keep imports out of your namespace
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>2:../../devel/p5-Moose
DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/namespace/autoclean/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
