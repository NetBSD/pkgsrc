# $NetBSD: Makefile,v 1.11 2005/10/10 10:48:49 dillo Exp $
#

DISTNAME=	Config-General-2.27
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cfg
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
