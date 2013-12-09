# $NetBSD: Makefile,v 1.17 2013/12/09 14:17:52 obache Exp $

DISTNAME=	Digest-Hashcash-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5hca
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Hashcash/
COMMENT=	Perl5 extension module for hashcash hashes
LICENSE=	gnu-gpl-v2

DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.2}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Digest/Hashcash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
