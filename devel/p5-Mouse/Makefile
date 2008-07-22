# $NetBSD: Makefile,v 1.1.1.1 2008/07/22 23:43:57 he Exp $

DISTNAME=	Mouse-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Class-Method-Modifiers>=0:../../devel/p5-Class-Method-Modifiers

PERL5_PACKLIST=	auto/Mouse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
