# $NetBSD: Makefile,v 1.1.1.1 2009/02/08 18:51:57 seb Exp $

DISTNAME=	MouseX-Types-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YA/YAPPO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MouseX-Types/
COMMENT=	Perl 5 module to organize Mouse types in libraries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/MouseX/Types/.packlist

DEPENDS+=	p5-Mouse>=0.15:../../devel/p5-Mouse

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
