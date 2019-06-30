# $NetBSD: Makefile,v 1.20 2019/06/30 20:14:38 nia Exp $

DISTNAME=	Class-Adapter-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
