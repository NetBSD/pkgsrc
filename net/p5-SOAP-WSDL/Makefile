# $NetBSD: Makefile,v 1.1 2023/06/09 19:43:42 gdt Exp $

DISTNAME=	SOAP-WSDL-3.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/SOAP::WSDL
COMMENT=	SOAP with WSDL support (deprecated)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0:../../devel/p5-Class-Load
DEPENDS+=	p5-Class-Std-Fast>=0.0.8:../../devel/p5-Class-Std-Fast
DEPENDS+=	p5-Data-Dumper>=0:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Module-Build>=0:../../devel/p5-Module-Build
DEPENDS+=	# TODO: p5-Template>=2.18
DEPENDS+=	p5-Term-ReadKey>=0:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	# TODO: p5-perl>=5.008

PERL5_PACKLIST=	auto/SOAP/WSDL/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
