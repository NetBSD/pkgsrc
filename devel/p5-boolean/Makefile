# $NetBSD: Makefile,v 1.22 2019/06/30 20:16:03 nia Exp $

DISTNAME=	boolean-0.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://metacpan.org/release/boolean
COMMENT=	Boolean support for Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
