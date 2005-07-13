# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:23 jlam Exp $
#

DISTNAME=	Config-General-2.27
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cfg
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.daemon.de/config-general/
COMMENT=	Perl Generic Config module

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
