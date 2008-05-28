# $NetBSD: Makefile,v 1.2 2008/05/28 21:58:04 abs Exp $

DISTNAME=	Data-OptList-0.103
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-OptList/
COMMENT=	Parse and validate simple name/value option pairs

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/OptList/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
