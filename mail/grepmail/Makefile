# $NetBSD: Makefile,v 1.2 2000/01/24 14:19:56 agc Exp $
#

DISTNAME=	grepmail-4.11
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.virginia.edu/~dwc3q/code/

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://www.cs.virginia.edu/~dwc3q/code/index.html

CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl

USE_PERL5=	yes

do-build:
	@cd ${WRKSRC} ;						\
	for i in 1 2 ; do					\
		${ECHO} "$$i" | ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL; \
		${MAKE};					\
		${RM} -f grepmail-$$i;				\
		${SED} -e '1s|.*|#! ${PREFIX}/bin/perl|' grepmail > grepmail-$$i; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/grepmail-1 ${PREFIX}/bin/grepmail-quick
	${INSTALL_SCRIPT} ${WRKSRC}/grepmail-2 ${PREFIX}/bin/grepmail-full
	${RM} -f ${PREFIX}/bin/grepmail
	${LN} -s grepmail-full ${PREFIX}/bin/grepmail

.include "../../mk/bsd.pkg.mk"
