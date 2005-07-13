# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:37 jlam Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

PERL5_PACKLIST=		auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
