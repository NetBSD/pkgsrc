# $NetBSD: Makefile,v 1.4 2012/12/11 10:01:38 dsainty Exp $
#

DISTNAME=	Data-AMF-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TY/TYPESTER/

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Data::AMF
COMMENT=	Serialise/deserialise AMF Packets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Data/AMF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
