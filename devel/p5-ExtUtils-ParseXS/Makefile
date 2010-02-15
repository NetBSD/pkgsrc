# $NetBSD: Makefile,v 1.12 2010/02/15 13:42:57 sno Exp $

DISTNAME=	ExtUtils-ParseXS-2.2203
PKGNAME=	p5-${DISTNAME:S/2203/22.03/}
SVR4_PKGNAME=	p5epx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ParseXS/
COMMENT=	Perl5 module for converting Perl XS code into C code
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/ExtUtils/ParseXS/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
