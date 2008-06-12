# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=		IO-Interface-1.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ioi
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~lds/IO-Interface/
COMMENT=		IO-Interface - get and set interface characteristics

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
