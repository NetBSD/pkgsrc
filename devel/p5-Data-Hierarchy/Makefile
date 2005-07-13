# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:24 jlam Exp $

DISTNAME=	Data-Hierarchy-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for handling data in a hierarchical structure

DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/Hierarchy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
