# $NetBSD: Makefile,v 1.47 2018/04/22 11:54:57 wen Exp $

DISTNAME=	Storable-3.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Storable/
COMMENT=	Perl extension module for persistent data storage
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
