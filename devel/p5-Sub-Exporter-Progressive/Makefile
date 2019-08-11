# $NetBSD: Makefile,v 1.16 2019/08/11 13:20:22 wiz Exp $

DISTNAME=	Sub-Exporter-Progressive-0.001013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Exporter-Progressive
COMMENT=	Only use Sub::Exporter if you need it
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/Progressive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
