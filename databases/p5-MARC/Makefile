# $NetBSD: Makefile,v 1.25 2019/08/11 13:18:30 wiz Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marcpm.sourceforge.net/
COMMENT=	Perl5 module for manipulating MARC (MAchine Readable Cataloging) data
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
