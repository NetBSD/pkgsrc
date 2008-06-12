# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:17 joerg Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mrc
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for manipulating MARC (MAchine Readable Cataloging) data

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
