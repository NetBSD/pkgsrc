# $NetBSD: Makefile,v 1.11 2017/10/15 04:11:04 wen Exp $

DISTNAME=	Digest-SHA3-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-SHA3/
COMMENT=	Perl5 module for SHA-3
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Digest/SHA3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
