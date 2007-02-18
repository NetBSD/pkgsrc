# $NetBSD: Makefile,v 1.20 2007/02/18 02:39:23 wiz Exp $

DISTNAME=	BSD-Resource-1.28
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BSD-Resource/
COMMENT=	Perl interface to BSD process resources library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
