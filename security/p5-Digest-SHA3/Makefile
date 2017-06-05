# $NetBSD: Makefile,v 1.8 2017/06/05 14:24:33 ryoon Exp $

DISTNAME=	Digest-SHA3-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-SHA3/
COMMENT=	Perl5 module for SHA-3
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Digest/SHA3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
