# $NetBSD: Makefile,v 1.1.1.1 2005/07/14 23:02:13 adrianp Exp $
#

DISTNAME=	POE-Component-Client-Ident-0.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/POE-Component-Client-Ident-0.7/
COMMENT=	Non-blocking ident lookups to your sessions.

DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		auto/POE/Component/Client/Ident/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
