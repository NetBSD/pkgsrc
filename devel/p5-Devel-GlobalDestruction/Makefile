# $NetBSD: Makefile,v 1.10 2012/10/31 11:18:00 asau Exp $

DISTNAME=	Devel-GlobalDestruction-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-GlobalDestruction/
COMMENT=	Perl 5 package exposing the flag which marks global destruction
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001.002:../../devel/p5-Sub-Exporter-Progressive

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/GlobalDestruction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
