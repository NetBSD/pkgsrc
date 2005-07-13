# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:24 jlam Exp $

DISTNAME=	Data-UUID-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for generating UUIDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/UUID/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
