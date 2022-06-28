# $NetBSD: Makefile,v 1.4 2022/06/28 11:32:07 wiz Exp $

DISTNAME=	Config-Onion-1.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Config::Onion
COMMENT=	Layered configuration, because configs are like ogres
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Any>=0:../../devel/p5-Config-Any
DEPENDS+=	p5-Hash-Merge-Simple>=0:../../devel/p5-Hash-Merge-Simple
DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo

PERL5_PACKLIST=	auto/Config/Onion/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
