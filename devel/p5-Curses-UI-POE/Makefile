# $NetBSD: Makefile,v 1.23 2019/06/30 20:14:47 nia Exp $

DISTNAME=	Curses-UI-POE-0.04
# 0.035 -> 0.03500, 0.04 -> 0.04000
PKGNAME=	p5-${DISTNAME:C/[0-9.]+//}0.04000
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Curses-UI-POE
COMMENT=	Subclass for Curses::UI that enables it to work with POE
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-Curses-UI>=0:../../devel/p5-Curses-UI
DEPENDS+=	p5-POE>=0.11:../../devel/p5-POE

PERL5_PACKLIST=		auto/Curses/UI/POE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
