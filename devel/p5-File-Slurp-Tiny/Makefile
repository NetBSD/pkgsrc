# $NetBSD: Makefile,v 1.6 2016/06/08 19:22:58 wiz Exp $

DISTNAME=	File-Slurp-Tiny-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp-Tiny/
COMMENT=	Simple, sane and efficient file slurper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
