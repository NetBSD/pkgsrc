# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:07 wiz Exp $

DISTNAME=	Class-Adapter-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Adapter/
COMMENT=	Perl 5 module implementing the adapter design pattern
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Class/Adapter/.packlist

post-extract:
	chmod -x ${WRKSRC}/lib/Class/*.pm ${WRKSRC}/lib/Class/Adapter/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
