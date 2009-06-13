# $NetBSD: Makefile,v 1.3 2009/06/13 06:46:44 rillig Exp $

DISTNAME=	Devel-LexAlias-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Devel::LexAlias
COMMENT=	Alias lexical variables

DEPENDS+=	p5-Devel-Caller>0.03:../../devel/p5-Devel-Caller

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Devel/LexAlias/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
