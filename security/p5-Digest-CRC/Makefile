# $NetBSD: Makefile,v 1.27 2017/06/05 14:24:32 ryoon Exp $

DISTNAME=	Digest-CRC-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-CRC/
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms
LICENSE=	public-domain

PERL5_PACKLIST=		auto/Digest/CRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
