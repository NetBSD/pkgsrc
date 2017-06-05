# $NetBSD: Makefile,v 1.2 2017/06/05 14:22:40 ryoon Exp $

DISTNAME=	Carp-1.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Carp/
COMMENT=	Alternative warn and die for modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Carp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
