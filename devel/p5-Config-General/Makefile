# $NetBSD: Makefile,v 1.7 2004/12/20 11:30:59 grant Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
