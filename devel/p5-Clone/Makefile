# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 04:40:51 epg Exp $

DISTNAME=	Clone-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for recursively copying datatypes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
