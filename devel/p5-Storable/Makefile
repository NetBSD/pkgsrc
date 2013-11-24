# $NetBSD: Makefile,v 1.39 2013/11/24 09:58:21 wiz Exp $

DISTNAME=	Storable-2.45
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Storable/
COMMENT=	Perl extension module for persistent data storage
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
