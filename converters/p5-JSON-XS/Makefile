# $NetBSD: Makefile,v 1.6 2008/10/12 21:26:34 he Exp $
#

DISTNAME=	JSON-XS-2.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-XS/
COMMENT=	JSON serialising/deserialising, done correctly and fast

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/JSON/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
