# $NetBSD: Makefile,v 1.28 2011/08/09 09:15:01 adam Exp $

DISTNAME=	BSD-Resource-1.2904
PKGNAME=	p5-${DISTNAME:S/2904/29.04/}
PKGREVISION=	2
SVR4_PKGNAME=	p5bsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BSD-Resource/
COMMENT=	Perl interface to BSD process resources library
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

UNLIMIT_RESOURCES+=	stacksize

PERL5_PACKLIST=		auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
