# $NetBSD: Makefile,v 1.22 2019/07/01 21:50:09 nia Exp $
#

DISTNAME=	Geo-IPfree-1.151940
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BRICAS/${DISTNAME}
COMMENT=	Gets country name by IP or hostname
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
