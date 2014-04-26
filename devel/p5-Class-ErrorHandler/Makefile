# $NetBSD: Makefile,v 1.11 2014/04/26 05:10:21 wen Exp $

DISTNAME=	Class-ErrorHandler-0.03
PKGNAME=	p5-${DISTNAME}
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

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
