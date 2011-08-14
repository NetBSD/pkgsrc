# $NetBSD: Makefile,v 1.17 2011/08/14 14:14:50 obache Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		5
CATEGORIES=		net perl5
MASTER_SITES=		http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
