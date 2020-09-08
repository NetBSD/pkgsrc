# $NetBSD: Makefile,v 1.14 2020/09/08 13:16:33 wiz Exp $
#

DISTNAME=	Data-AMF-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TY/TYPESTER/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::AMF
COMMENT=	Serialise/deserialise AMF Packets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Data/AMF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
