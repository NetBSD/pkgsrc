# $NetBSD: Makefile,v 1.2 2007/06/09 23:32:58 abs Exp $

DISTNAME=	ExtUtils-ParseXS-2.18
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5epx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ParseXS/
COMMENT=	Perl5 module for converting Perl XS code into C code

PERL5_PACKLIST=	auto/ExtUtils/ParseXS/.packlist

DEPENDS+=	p5-ExtUtils-CBuilder-[0-9]*:../../devel/p5-ExtUtils-CBuilder

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
