# $NetBSD: Makefile,v 1.1.1.1 2005/11/07 11:27:31 martti Exp $

DISTNAME=	Curses-UI-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses-UI
COMMENT=	Curses based user user interface framework

DEPENDS+=	p5-Curses>=1.05:../../devel/p5-Curses
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Test-Pod>=1.20:../../devel/p5-Test-Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Curses/UI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
