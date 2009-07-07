# $NetBSD: Makefile,v 1.15 2009/07/07 21:23:47 sno Exp $
#

DISTNAME=	Set-Scalar-1.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ssc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Scalar/
COMMENT=	Perl5 module for basic set operations
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
