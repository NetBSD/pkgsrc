# $NetBSD: Makefile,v 1.15 2017/06/05 14:22:29 ryoon Exp $

DISTNAME=		MARC-Record-2.0.6
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MARC-Record/
COMMENT=		MARC record handling package
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
