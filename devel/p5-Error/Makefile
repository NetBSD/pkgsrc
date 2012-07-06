# $NetBSD: Makefile,v 1.23 2012/07/06 10:21:17 sno Exp $

DISTNAME=	Error-0.17018
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5err
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Error/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Error/
COMMENT=	Perl extension module for try/throw/catch exception handling
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Error/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
