# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 04:40:54 epg Exp $

DISTNAME=	Data-Hierarchy-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for handling data in a hierarchical structure

DEPENDS+=	p5-Clone>=0.15:../../devel/p5-Clone

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Hierarchy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
