# $NetBSD: Makefile,v 1.25 2023/07/06 09:39:01 wiz Exp $

DISTNAME=	Devel-GlobalDestruction-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-GlobalDestruction
COMMENT=	Perl 5 package exposing the flag which marks global destruction
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001011:../../devel/p5-Sub-Exporter-Progressive

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/GlobalDestruction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
