# $NetBSD: Makefile,v 1.43 2021/11/30 00:35:14 wen Exp $

DISTNAME=	Event-1.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Event
COMMENT=	Event library for Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
