# $NetBSD: Makefile,v 1.1.1.1 1999/06/08 12:01:13 bad Exp $
#

DISTNAME=	grepmail-3.8
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.virginia.edu/~dwc3q/code/

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://www.cs.virginia.edu/~dwc3q/code/index.html

CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl

USE_PERL5=	yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl specialize grepmail.in < /dev/null

do-build:
	@cd ${WRKSRC} && \
	${SED} -e '1s,.*,#!'${PREFIX}/bin/perl',' grepmail >grepmail.perl && \
	${MV} -f grepmail.perl grepmail
	@echo Build done.

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/grepmail ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
