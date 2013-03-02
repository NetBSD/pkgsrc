# $NetBSD: Makefile,v 1.8 2013/03/02 10:44:34 tron Exp $

DISTNAME=	Class-ErrorHandler-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5ceh
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-ErrorHandler/
COMMENT=	Perl base class for error handling
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/ErrorHandler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
