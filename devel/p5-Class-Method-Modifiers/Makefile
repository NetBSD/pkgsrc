# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:49 he Exp $

DISTNAME=	Class-Method-Modifiers-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
