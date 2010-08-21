# $NetBSD: Makefile,v 1.16 2010/08/21 16:35:33 seb Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		4
CATEGORIES=		net perl5
MASTER_SITES=		http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
