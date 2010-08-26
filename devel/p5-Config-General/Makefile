# $NetBSD: Makefile,v 1.21 2010/08/26 05:11:23 sno Exp $
#

DISTNAME=	Config-General-2.49
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
SVR4_PKGNAME=	p5cfg
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
