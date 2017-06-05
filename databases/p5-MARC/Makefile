# $NetBSD: Makefile,v 1.23 2017/06/05 14:22:29 ryoon Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marcpm.sourceforge.net/
COMMENT=	Perl5 module for manipulating MARC (MAchine Readable Cataloging) data
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
