# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:13 wiz Exp $

DISTNAME=	File-Slurp-Tiny-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Slurp-Tiny
COMMENT=	Simple, sane and efficient file slurper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
