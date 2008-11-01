# $NetBSD: Makefile,v 1.4 2008/11/01 21:44:34 seb Exp $

DISTNAME=	Mouse-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system

PKG_DESTDIR_SUPPORT=	user-destdir

# For tests
#BUILD_DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
#BUILD_DEPENDS+=	p5-Moose>=0.59:../../devel/p5-Moose

PERL5_PACKLIST=	auto/Mouse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
