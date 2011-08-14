# $NetBSD: Makefile,v 1.12 2011/08/14 14:14:48 obache Exp $
#

DISTNAME=	RADIUS-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5rad
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RADIUS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chrmasto/RADIUS-1.0/
COMMENT=	Perl5 module for RADIUS queries

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/RADIUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
