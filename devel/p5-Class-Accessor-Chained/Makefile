# $NetBSD: Makefile,v 1.7 2012/10/03 21:54:41 wiz Exp $

DISTNAME=	Class-Accessor-Chained-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5cac
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Chained/
COMMENT=	Make chained accessors
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor

PERL5_PACKLIST=		auto/Class/Accessor/Chained/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
