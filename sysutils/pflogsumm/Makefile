# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:29 jmmv Exp $
#

DISTNAME=		pflogsumm-1.0.4
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://jimsun.linxnet.com/pub/postfix_contrib/
EXTRACT_SUFX=		.pl
EXTRACT_ONLY=		# empty

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://jimsun.linxnet.com/postfix_contrib.html
COMMENT=		Produce summaries from Postfix syslog data

DEPENDS+=		p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		# defined
USE_PERL5=		# defined

do-build:
	${SED} 's;/usr/bin/perl;${PERL5};' ${DISTDIR}/${DISTFILES} \
	    > ${WRKDIR}/pflogsumm

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pflogsumm ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
