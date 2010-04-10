# $NetBSD: Makefile,v 1.1.1.1 2010/04/10 14:20:21 seb Exp $
#

DISTNAME=	Module-Install-XSUtil-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-XSUtil/
COMMENT=	Perl 5 module providing utility functions for XS modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c # for test target
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Module/Install/XSUtil/.packlist

BUILD_DEPENDS+=	p5-Devel-PPPort>=3.19:../../devel/p5-Devel-PPPort
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-Test-Simple>=0.88:../../devel/p5-Test-Simple

DEPENDS+=	p5-Module-Install>=0.91:../../devel/p5-Module-Install

.include "../../devel/p5-B-Hooks-OP-Annotation/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
