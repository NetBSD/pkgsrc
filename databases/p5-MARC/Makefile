# $NetBSD: Makefile,v 1.12 2008/10/19 19:17:45 he Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mrc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for manipulating MARC (MAchine Readable Cataloging) data

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
