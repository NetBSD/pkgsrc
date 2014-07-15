# $NetBSD: Makefile,v 1.25 2014/07/15 20:52:03 schmonz Exp $

DISTNAME=	ExtUtils-ParseXS-3.24
PKGNAME=	p5-${DISTNAME}
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
