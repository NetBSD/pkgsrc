# $NetBSD: Makefile,v 1.11 2017/09/16 19:26:59 wiz Exp $
#

DISTNAME=	Mail-DeliveryStatus-BounceParser-1.542
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rjbs/Mail-DeliveryStatus-BounceParser-1.540/lib/Mail/DeliveryStatus/BounceParser.pm
COMMENT=	Perl extension to analyze bounce messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-tools>=5.418:../../mail/p5-MIME-tools

USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
