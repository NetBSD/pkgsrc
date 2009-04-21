# $NetBSD: Makefile,v 1.1.1.1 2009/04/21 17:46:39 schmonz Exp $
#

DISTNAME=	Math-Round-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Round/
COMMENT=	Perl extension for rounding numbers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Math/Round/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
