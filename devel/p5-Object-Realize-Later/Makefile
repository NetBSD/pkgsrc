# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:25 obache Exp $

DISTNAME=	Object-Realize-Later-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-Realize-Later/
COMMENT=	Delayed creation of objects

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
