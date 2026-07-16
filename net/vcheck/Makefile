# $NetBSD: Makefile,v 1.33 2026/07/16 19:04:37 wiz Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		19
CATEGORIES=		net perl5
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
