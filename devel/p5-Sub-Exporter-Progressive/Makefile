# $NetBSD: Makefile,v 1.14 2018/08/22 09:44:39 wiz Exp $

DISTNAME=	Sub-Exporter-Progressive-0.001013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-Progressive/
COMMENT=	Only use Sub::Exporter if you need it
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/Progressive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
