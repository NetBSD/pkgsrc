# $NetBSD: Makefile,v 1.3 2003/07/17 21:28:40 grant Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mrc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	perl5 module for manipulating MARC (MAchine Readable Cataloging) data

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
