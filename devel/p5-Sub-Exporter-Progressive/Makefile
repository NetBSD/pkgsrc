# $NetBSD: Makefile,v 1.6 2013/07/03 16:37:38 sno Exp $

DISTNAME=	Sub-Exporter-Progressive-0.001010
PKGNAME=	p5-${DISTNAME}
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
