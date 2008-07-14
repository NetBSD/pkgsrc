# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:24:50 abs Exp $

DISTNAME=	Devel-Caller-2.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Devel::Caller
COMMENT=	Meatier versions of caller

DEPENDS+=       p5-PadWalker>0.08:../../devel/p5-PadWalker

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Devel/Caller/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
