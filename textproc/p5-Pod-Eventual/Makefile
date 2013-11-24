# $NetBSD: Makefile,v 1.5 2013/11/24 04:17:35 wen Exp $

DISTNAME=	Pod-Eventual-0.094001
PKGNAME=	p5-${DISTNAME:S/094001/094.001/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Eventual/
COMMENT=	Read a POD document as a series of trivial events
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mixin-Linewise>=0.102:../../devel/p5-Mixin-Linewise

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Pod/Eventual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
