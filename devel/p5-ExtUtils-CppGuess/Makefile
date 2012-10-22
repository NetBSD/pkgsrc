# $NetBSD: Makefile,v 1.1 2012/10/22 13:45:54 wiz Exp $

DISTNAME=	ExtUtils-CppGuess-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~smueller/ExtUtils-CppGuess/
COMMENT=	Perl5 module for guess C++ compiler and flags
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PKG_DESTDIR_SUPPORT=	user-destdir

#USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/CppGuess/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
