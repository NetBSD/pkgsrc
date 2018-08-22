# $NetBSD: Makefile,v 1.2 2018/08/22 09:43:53 wiz Exp $

DISTNAME=	Devel-Caller-IgnoreNamespaces-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Caller-IgnoreNamespaces/
COMMENT=	Provide caller that ignores specific namespaces
LICENSE=	artistic OR gnu-gpl-v2

#USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/Caller/IgnoreNamespaces/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
