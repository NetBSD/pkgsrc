# $NetBSD: Makefile,v 1.1.1.1 2004/05/09 05:39:00 minskim Exp $
#

DISTNAME=	Data-TemporaryBag-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?dist=Data-TemporaryBag
COMMENT=	Handle long size data using temporary file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Data/TemporaryBag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
