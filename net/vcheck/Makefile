# $NetBSD: Makefile,v 1.12 2005/12/27 13:54:59 seb Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
