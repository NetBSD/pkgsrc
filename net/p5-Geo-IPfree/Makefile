# $NetBSD: Makefile,v 1.26 2022/03/19 23:47:13 wen Exp $
#

DISTNAME=	Geo-IPfree-1.160000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BRICAS/${DISTNAME}
COMMENT=	Gets country name by IP or hostname
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
