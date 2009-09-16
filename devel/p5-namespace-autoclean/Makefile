# $NetBSD: Makefile,v 1.2 2009/09/16 17:35:17 sno Exp $

DISTNAME=	namespace-autoclean-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-autoclean/
COMMENT=	Keep imports out of your namespace
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.07:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-Class-MOP>=0.80:../../devel/p5-Class-MOP
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/namespace/autoclean/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
