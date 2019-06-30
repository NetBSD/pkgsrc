# $NetBSD: Makefile,v 1.15 2019/06/30 20:14:15 nia Exp $

DISTNAME=	SMS-Send-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SMS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SMS-Send
COMMENT=	Driver-based API for sending SMS messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable>=3.7:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util
DEPENDS+=	p5-Class-Adapter>=1.05:../../devel/p5-Class-Adapter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/SMS/Send/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
