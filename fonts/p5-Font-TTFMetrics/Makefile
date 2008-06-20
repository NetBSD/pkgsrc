# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:19 joerg Exp $
#

DISTNAME=	Font-TTFMetrics-0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl parser for the True type font metric (TTF) files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Font/TTFMetrics/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
