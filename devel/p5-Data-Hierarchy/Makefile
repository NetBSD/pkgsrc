# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:30 tv Exp $

DISTNAME=	Data-Hierarchy-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for handling data in a hierarchical structure

DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Hierarchy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
