# $NetBSD: Makefile,v 1.10 2012/12/19 07:22:17 wen Exp $
#

DISTNAME=	Geo-IPfree-1.122880
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bricas/${DISTNAME}/
COMMENT=	Gets country name by IP or hostname
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
