# $NetBSD: Makefile,v 1.4 2008/08/12 09:41:17 martti Exp $

DISTNAME=	Curses-UI-POE-0.031
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses-UI-POE
COMMENT=	Subclass for Curses::UI that enables it to work with POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Curses-UI>=0:../../devel/p5-Curses-UI

PERL5_PACKLIST=		auto/Curses/UI/POE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
