# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:42 obache Exp $

DISTNAME=	Test-MockObject-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-MockObject/
COMMENT=	Tests remote URLs or local web files

DEPENDS+=	p5-UNIVERSAL-can>=1.00:../../devel/p5-UNIVERSAL-can
DEPENDS+=	p5-UNIVERSAL-isa>=0.02:../../devel/p5-UNIVERSAL-isa
BUILD_DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0:../../devel/p5-Test-Warn

INSTALL_TARGET=	pure_install

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/MockObject/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
