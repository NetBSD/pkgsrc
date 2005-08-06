# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:30 jlam Exp $
#

DISTNAME=	Digest-Hashcash-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hca
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Hashcash/
COMMENT=	Perl5 extension module for hashcash hashes

DEPENDS+=	p5-Time-HiRes>=1.2:../../time/p5-Time-HiRes


PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		auto/Digest/Hashcash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
