# $NetBSD: Makefile,v 1.4 2008/10/19 19:18:10 he Exp $
#

DISTNAME=	Font-TTFMetrics-0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl parser for the True type font metric (TTF) files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Font/TTFMetrics/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
