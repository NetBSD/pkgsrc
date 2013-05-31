# $NetBSD: Makefile,v 1.5 2013/05/31 12:40:11 wiz Exp $

DISTNAME=	Config-Grammar-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Grammar/
COMMENT=	Grammar-based, user-friendly config parser
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Config/Grammar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
