# $NetBSD: Makefile,v 1.3 2007/07/29 16:26:08 joerg Exp $

DISTNAME=	ExtUtils-CBuilder-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ecb
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-CBuilder/
COMMENT=	Perl5 module for compiling and linking C code for Perl modules

PERL5_PACKLIST=	auto/ExtUtils/CBuilder/.packlist

REPLACE_PERL=	bleadcheck.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
