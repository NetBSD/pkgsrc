# $NetBSD: Makefile,v 1.30 2023/12/28 23:22:48 zafer Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		16
CATEGORIES=		net perl5
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
