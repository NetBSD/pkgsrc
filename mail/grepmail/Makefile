# $NetBSD: Makefile,v 1.5 2001/02/17 18:24:48 wiz Exp $
#

DISTNAME=	grepmail-4.45
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	mbox formatted file search utility

USE_PERL5=	# defined
CONFIGURE_ENV=	PERL=${PERL5}
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/grepmail/.packlist

do-build:
	@cd ${WRKSRC} ;						\
	for i in 1 2 ; do					\
		${ECHO} "$$i" | ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL; \
		${MAKE};					\
		${RM} -f grepmail-$$i;				\
		${SED} -e '1s|.*|#! ${PERL5}|' grepmail > grepmail-$$i; \
	done

do-install:
	@cd ${WRKSRC} ;						\
	${MAKE} install
	${INSTALL_SCRIPT} ${WRKSRC}/grepmail-1 ${PREFIX}/bin/grepmail-quick
	${INSTALL_SCRIPT} ${WRKSRC}/grepmail-2 ${PREFIX}/bin/grepmail-full
	${RM} -f ${PREFIX}/bin/grepmail
	${LN} -s grepmail-full ${PREFIX}/bin/grepmail

.include "../../mk/bsd.pkg.mk"
