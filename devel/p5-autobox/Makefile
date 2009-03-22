# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 14:37:44 seb Exp $
#

DISTNAME=	autobox-2.55
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHOCOLATE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox/
COMMENT=	Perl 5 module to add methods on native types

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/autobox/.packlist

DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
