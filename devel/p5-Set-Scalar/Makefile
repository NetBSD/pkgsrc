# $NetBSD: Makefile,v 1.21 2013/05/31 12:40:43 wiz Exp $
#

DISTNAME=	Set-Scalar-1.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5ssc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Scalar/
COMMENT=	Perl5 module for basic set operations
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
