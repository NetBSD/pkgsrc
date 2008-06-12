# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=		Net-Ident-1.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nid
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Ident/
COMMENT=		Perl module implementing the client side of the ident protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#empty

PERL5_PACKLIST=		auto/Net/Ident/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
