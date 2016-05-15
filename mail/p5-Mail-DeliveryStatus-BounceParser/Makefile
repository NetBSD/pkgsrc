# $NetBSD: Makefile,v 1.8 2016/05/15 12:56:08 wen Exp $
#

DISTNAME=	Mail-DeliveryStatus-BounceParser-1.542
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rjbs/Mail-DeliveryStatus-BounceParser-1.540/lib/Mail/DeliveryStatus/BounceParser.pm
COMMENT=	Perl extension to analyze bounce messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-tools>=5.418:../../mail/p5-MIME-tools

USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
