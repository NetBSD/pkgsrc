# $NetBSD: Makefile,v 1.1.1.1 2010/04/28 20:40:34 seb Exp $
#

DISTNAME=	Class-Field-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Field/
COMMENT=	Perl 5 class field accessor generator
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/Field/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
