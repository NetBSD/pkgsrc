# $NetBSD: Makefile,v 1.1.1.1 2006/02/15 00:30:01 heinz Exp $
#

DISTNAME=		Class-ErrorHandler-0.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ceh
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-ErrorHandler/
COMMENT=		Perl base class for error handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Class/ErrorHandler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
