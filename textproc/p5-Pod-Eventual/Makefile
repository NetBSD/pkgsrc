# $NetBSD: Makefile,v 1.1 2012/07/05 15:17:06 sno Exp $

DISTNAME=	Pod-Eventual-0.093330
PKGNAME=	p5-${DISTNAME:S/093330/093.330/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Eventual/
COMMENT=	Read a POD document as a series of trivial events
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mixin-Linewise>=0.001:../../devel/p5-Mixin-Linewise

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/Eventual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
