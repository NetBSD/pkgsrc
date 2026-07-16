# $NetBSD: Makefile,v 1.28 2026/07/16 19:02:00 wiz Exp $

DISTNAME=	Class-Adapter-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Adapter
COMMENT=	Perl 5 module implementing the adapter design pattern
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Class/Adapter/.packlist

post-extract:
	chmod a-x ${WRKSRC}/lib/Class/*.pm ${WRKSRC}/lib/Class/Adapter/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
