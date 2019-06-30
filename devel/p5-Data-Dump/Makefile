# $NetBSD: Makefile,v 1.21 2019/06/30 20:14:48 nia Exp $

DISTNAME=	Data-Dump-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Dump
COMMENT=	Pretty printing of data structures
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
