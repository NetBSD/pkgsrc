# $NetBSD: Makefile,v 1.12 2018/08/22 09:43:04 wiz Exp $
#

DISTNAME=	Device-XBee-API-0.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JE/JEAGLE/

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Device::XBee::API
COMMENT=	Object-oriented Perl interface to Digi XBee module API mode
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Device-SerialPort>=1.04:../../comms/p5-Device-SerialPort

WRKSRC=		${WRKDIR}/Device-XBee-API
USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Device/XBee/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
