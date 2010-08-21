# $NetBSD: Makefile,v 1.17 2010/08/21 16:33:40 seb Exp $

DISTNAME=	ExtUtils-CBuilder-0.2703
PKGNAME=	p5-ExtUtils-CBuilder-0.27.03
PKGREVISION=	1
SVR4_PKGNAME=	p5ecb
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-CBuilder/
COMMENT=	Perl5 module for compiling and linking C code for Perl modules
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/CBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
