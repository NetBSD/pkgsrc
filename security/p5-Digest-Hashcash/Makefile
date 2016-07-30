# $NetBSD: Makefile,v 1.23 2016/07/30 23:56:01 wen Exp $

DISTNAME=	Digest-Hashcash-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Hashcash/
COMMENT=	Perl5 extension module for hashcash hashes
LICENSE=	gnu-gpl-v2

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.2}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Digest/Hashcash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
