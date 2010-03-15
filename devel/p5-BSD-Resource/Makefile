# $NetBSD: Makefile,v 1.26 2010/03/15 17:05:44 sno Exp $

DISTNAME=	BSD-Resource-1.2904
PKGNAME=	p5-${DISTNAME:S/2904/29.04/}
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

PERL5_PACKLIST=	auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
