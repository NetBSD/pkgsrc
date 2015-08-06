# $NetBSD: Makefile,v 1.5 2015/08/06 03:36:25 wen Exp $

DISTNAME=	File-Slurp-Tiny-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp-Tiny/
COMMENT=	Simple, sane and efficient file slurper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
