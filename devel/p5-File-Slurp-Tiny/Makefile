# $NetBSD: Makefile,v 1.8 2018/08/22 09:44:02 wiz Exp $

DISTNAME=	File-Slurp-Tiny-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp-Tiny/
COMMENT=	Simple, sane and efficient file slurper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
