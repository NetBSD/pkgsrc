# $NetBSD: Makefile,v 1.16 2015/02/20 07:15:29 mef Exp $
#

DISTNAME=	Geo-IPfree-1.143630
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bricas/${DISTNAME}/
COMMENT=	Gets country name by IP or hostname
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
