# $NetBSD: Makefile,v 1.5 2018/08/22 09:45:37 wiz Exp $

DISTNAME=	Math-Base-Convert-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Base-Convert/
COMMENT=	Very fast base to base conversion
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/Base/Convert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
