# $NetBSD: Makefile,v 1.16 2012/10/02 21:25:32 asau Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5mrc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marcpm.sourceforge.net/
COMMENT=	Perl5 module for manipulating MARC (MAchine Readable Cataloging) data
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
