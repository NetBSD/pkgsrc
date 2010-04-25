# $NetBSD: Makefile,v 1.4 2010/04/25 12:07:52 seb Exp $

DISTNAME=	ExtUtils-XSpp-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-XSpp/
COMMENT=	XS for C++
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=	p5-ExtUtils-ParseXS>=2.22.02:../../devel/p5-ExtUtils-ParseXS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/XSpp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
