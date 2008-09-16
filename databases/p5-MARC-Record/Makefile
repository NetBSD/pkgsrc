# $NetBSD: Makefile,v 1.1.1.1 2008/09/16 18:04:23 he Exp $

DISTNAME=		MARC-Record-2.0.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MARC-Record/
COMMENT=		MARC record handling package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
