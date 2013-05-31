# $NetBSD: Makefile,v 1.13 2013/05/31 12:40:12 wiz Exp $

DISTNAME=	Curses-UI-0.9609
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses-UI
COMMENT=	Curses based user user interface framework
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Curses>=1.05:../../devel/p5-Curses
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
BUILD_DEPENDS+=	p5-Test-Pod>=1.20:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/Curses/UI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
