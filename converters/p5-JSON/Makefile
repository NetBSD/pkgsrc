# $NetBSD: Makefile,v 1.12 2010/01/20 14:50:17 wiz Exp $

DISTNAME=		JSON-2.17
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON/
COMMENT=		Perl module converts between JSON and Perl data structure
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
