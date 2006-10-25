# $NetBSD: Makefile,v 1.7 2006/10/25 13:56:45 obache Exp $
#

DISTNAME=	Data-TemporaryBag-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-TemporaryBag/
COMMENT=	Handle long size data using temporary file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Data/TemporaryBag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
