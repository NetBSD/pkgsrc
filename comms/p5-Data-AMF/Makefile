# $NetBSD: Makefile,v 1.3 2012/12/04 06:18:08 asau Exp $
#

DISTNAME=	Data-AMF-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TY/TYPESTER/

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Data::AMF
COMMENT=	Serialise/deserialise AMF Packets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Data/AMF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
