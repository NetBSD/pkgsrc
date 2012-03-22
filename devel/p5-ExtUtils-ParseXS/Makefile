# $NetBSD: Makefile,v 1.19 2012/03/22 13:33:26 sno Exp $

DISTNAME=	ExtUtils-ParseXS-3.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5epx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-ParseXS/
COMMENT=	Perl5 module for converting Perl XS code into C code
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/ExtUtils/ParseXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
