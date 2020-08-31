# $NetBSD: Makefile,v 1.41 2020/08/31 18:06:29 wiz Exp $

DISTNAME=	Event-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Event
COMMENT=	Event library for Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
