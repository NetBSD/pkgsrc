# $NetBSD: Makefile,v 1.4 2024/01/15 18:03:04 wiz Exp $

DISTNAME=	Data-Entropy-0.007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::Entropy
COMMENT=	Perl module to manage entropy sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-Crypt-Rijndael>=0:../../security/p5-Crypt-Rijndael
DEPENDS+=	p5-Data-Float>=0:../../devel/p5-Data-Float
DEPENDS+=	p5-HTTP-Lite>=2.2:../../www/p5-HTTP-Lite
DEPENDS+=	p5-Params-Classify>=0:../../devel/p5-Params-Classify

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Data/Entropy/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
