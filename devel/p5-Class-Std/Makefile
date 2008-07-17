# $NetBSD: Makefile,v 1.3 2008/07/17 09:48:06 rhaen Exp $
#

DISTNAME=	Class-Std-0.0.9
PKGNAME=	p5-Class-Std-0.0.9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Std/
COMMENT=	Perl 5 module to support creation of standard inside-out classes

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

PERL5_PACKLIST=	auto/Class/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
