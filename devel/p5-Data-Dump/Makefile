# $NetBSD: Makefile,v 1.19 2017/06/05 14:22:47 ryoon Exp $

DISTNAME=	Data-Dump-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Dump/
COMMENT=	Pretty printing of data structures
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
