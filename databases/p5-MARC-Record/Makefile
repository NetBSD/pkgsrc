# $NetBSD: Makefile,v 1.16 2017/09/17 08:47:28 wiz Exp $

DISTNAME=		MARC-Record-2.0.7
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MARC-Record/
COMMENT=		MARC record handling package
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
