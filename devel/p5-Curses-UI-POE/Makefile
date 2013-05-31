# $NetBSD: Makefile,v 1.15 2013/05/31 12:40:12 wiz Exp $

DISTNAME=	Curses-UI-POE-0.035
PKGNAME=	p5-Curses-UI-POE-0.03500
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses-UI-POE
COMMENT=	Subclass for Curses::UI that enables it to work with POE
LICENSE=	gnu-gpl-v2 OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Curses-UI>=0:../../devel/p5-Curses-UI

PERL5_PACKLIST=		auto/Curses/UI/POE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
