# $NetBSD: Makefile,v 1.18 2018/08/22 09:44:25 wiz Exp $

DISTNAME=	NEXT-0.67
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NEXT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NEXT/
COMMENT=	Provide a pseudo-class NEXT (et al) that allows method redispatch
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/NEXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
