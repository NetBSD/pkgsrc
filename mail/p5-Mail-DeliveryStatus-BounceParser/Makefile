# $NetBSD: Makefile,v 1.14 2019/08/11 13:21:36 wiz Exp $
#

DISTNAME=	Mail-DeliveryStatus-BounceParser-1.542
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/RJBS/Mail-DeliveryStatus-BounceParser-1.540/lib/Mail/DeliveryStatus/BounceParser.pm
COMMENT=	Perl extension to analyze bounce messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-tools>=5.418:../../mail/p5-MIME-tools

USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
