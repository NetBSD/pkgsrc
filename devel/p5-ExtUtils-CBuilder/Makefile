# $NetBSD: Makefile,v 1.5 2008/01/08 22:56:10 heinz Exp $

DISTNAME=	ExtUtils-CBuilder-0.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ecb
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-CBuilder/
COMMENT=	Perl5 module for compiling and linking C code for Perl modules

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/CBuilder/.packlist

REPLACE_PERL=	bleadcheck.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
