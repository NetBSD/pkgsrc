# $NetBSD: Makefile,v 1.6 2004/03/26 02:27:50 wiz Exp $
#

DISTNAME=		vcheck-1.2.1
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/
COMMENT=		Latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
