# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:15 tsarna Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:06 jfitz Exp
#

DISTNAME=		Business-CreditCard-0.1
PKGNAME=		p5-Business-CreditCard-0.1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html

USE_PERL5=		YES

NO_BUILD=		YES

do-install:
		@ ${CP} ${WRKSRC}/CreditCard.pm ${WRKSRC}/CreditCard-0.1.pm
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/Business/
		@ ${INSTALL_DATA} ${WRKSRC}/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/Business/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/CreditCard.pm

.include "../../mk/bsd.pkg.mk"
