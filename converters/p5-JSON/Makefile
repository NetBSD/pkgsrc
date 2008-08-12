# $NetBSD: Makefile,v 1.7 2008/08/12 09:17:28 obache Exp $

DISTNAME=		JSON-2.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON/
COMMENT=		Perl module converts between JSON and Perl data structure

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
