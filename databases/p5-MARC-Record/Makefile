# $NetBSD: Makefile,v 1.20 2020/08/31 18:07:05 wiz Exp $

DISTNAME=		MARC-Record-2.0.7
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/MARC-Record
COMMENT=		MARC record handling package
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
