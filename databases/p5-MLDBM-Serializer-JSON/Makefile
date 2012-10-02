# $NetBSD: Makefile,v 1.3 2012/10/02 21:25:33 asau Exp $
#

DISTNAME=	MLDBM-Serializer-JSON-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MLDBM-Serializer-JSON/
COMMENT=	DBM serializer uses JSON for language interoperability
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty

DEPENDS+=	p5-MLDBM>=2.04:../../databases/p5-MLDBM
DEPENDS+=	p5-JSON-Any>=1.22:../../converters/p5-JSON-Any

PERL5_PACKLIST=		auto/MLDBM/Serializer/JSON/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
