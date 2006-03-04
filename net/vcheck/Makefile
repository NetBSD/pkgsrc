# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:25 jlam Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
