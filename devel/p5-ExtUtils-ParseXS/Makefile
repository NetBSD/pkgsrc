# $NetBSD: Makefile,v 1.22 2013/05/31 12:40:18 wiz Exp $

DISTNAME=	ExtUtils-ParseXS-3.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5epx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ParseXS/
COMMENT=	Perl5 module for converting Perl XS code into C code
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/ParseXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
