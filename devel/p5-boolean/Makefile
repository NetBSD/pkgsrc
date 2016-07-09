# $NetBSD: Makefile,v 1.19 2016/07/09 00:13:24 wen Exp $

DISTNAME=	boolean-0.46
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/boolean/
COMMENT=	Boolean support for Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
