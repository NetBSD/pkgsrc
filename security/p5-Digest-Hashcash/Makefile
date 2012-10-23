# $NetBSD: Makefile,v 1.14 2012/10/23 18:16:44 asau Exp $

DISTNAME=	Digest-Hashcash-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5hca
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Hashcash/
COMMENT=	Perl5 extension module for hashcash hashes
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Time-HiRes>=1.2:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Digest/Hashcash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
