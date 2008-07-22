# $NetBSD: Makefile,v 1.1.1.1 2008/07/22 23:18:55 he Exp $

DISTNAME=	Class-Method-Modifiers-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Method-Modifiers/
COMMENT=	Perl module providing Moose-like method modifiers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat

PERL5_PACKLIST=	auto/Class/Method/Modifiers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
