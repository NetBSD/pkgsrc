# $NetBSD: Makefile,v 1.14 2015/06/12 10:49:33 wiz Exp $

DISTNAME=	NEXT-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NEXT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NEXT/
COMMENT=	Provide a pseudo-class NEXT (et al) that allows method redispatch
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/NEXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
