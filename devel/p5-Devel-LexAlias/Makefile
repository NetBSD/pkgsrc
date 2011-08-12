# $NetBSD: Makefile,v 1.5 2011/08/12 08:21:32 adam Exp $

DISTNAME=	Devel-LexAlias-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-LexAlias/
COMMENT=	Alias lexical variables
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Devel-Caller>0.03:../../devel/p5-Devel-Caller

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/LexAlias/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
