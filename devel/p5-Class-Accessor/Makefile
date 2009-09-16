# $NetBSD: Makefile,v 1.14 2009/09/16 17:16:18 sno Exp $
#

DISTNAME=	Class-Accessor-0.34
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cac
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor/
COMMENT=	Automated accessor generation
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
