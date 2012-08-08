# $NetBSD: Makefile,v 1.1 2012/08/08 12:03:18 wen Exp $

DISTNAME=	Sub-Exporter-Progressive-0.001003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-Progressive/
COMMENT=	Only use Sub::Exporter if you need it
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/Progressive/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
