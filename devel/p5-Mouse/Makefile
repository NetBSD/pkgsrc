# $NetBSD: Makefile,v 1.7 2009/01/04 20:48:02 he Exp $

DISTNAME=	Mouse-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Method-Modifiers>=1.01:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
#BUILD_DEPENDS+= p5-Moose>=0.59:../../devel/p5-Moose

PERL5_PACKLIST=	auto/Mouse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
