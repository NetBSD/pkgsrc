# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 04:41:03 epg Exp $

DISTNAME=	Pod-Simple-3.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple framework for parsing Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
