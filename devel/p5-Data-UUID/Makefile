# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 17:05:24 epg Exp $

DISTNAME=	Data-UUID-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for generating UUIDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/UUID/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
