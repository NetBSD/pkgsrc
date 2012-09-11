# $NetBSD: Makefile,v 1.9 2012/09/11 23:04:28 asau Exp $

DISTNAME=	Number-Compare-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nbc
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Number-Compare/
COMMENT=	Compiles a simple comparison to an anonymous subroutine
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Number/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
