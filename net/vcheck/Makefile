# $NetBSD: Makefile,v 1.2 2003/06/02 01:17:39 jschauma Exp $
#

DISTNAME=		vcheck-1.2.1
CATEGORIES=		net perl5
MASTER_SITES=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.stud.tu-ilmenau.de/~gomar/stuff/vcheck/
COMMENT=		latest program version checker and auto-downloader

DEPENDS+=		p5-libwww>=5.69nb1:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/vcheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
