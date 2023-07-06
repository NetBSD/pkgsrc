# $NetBSD: Makefile,v 1.18 2023/07/06 09:39:06 wiz Exp $

DISTNAME=	Exception-Handler-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exception/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Exception-Handler
COMMENT=	Report exceptions with formatted text call-stack
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Exception/Handler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
