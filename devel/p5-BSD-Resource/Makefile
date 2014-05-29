# $NetBSD: Makefile,v 1.33 2014/05/29 23:35:40 wiz Exp $

DISTNAME=	BSD-Resource-1.2907
PKGNAME=	p5-${DISTNAME:S/2907/29.07/}
PKGREVISION=	1
SVR4_PKGNAME=	p5bsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BSD-Resource/
COMMENT=	Perl interface to BSD process resources library
LICENSE=	artistic-2.0 OR gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

UNLIMIT_RESOURCES+=	stacksize

PERL5_PACKLIST=		auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
