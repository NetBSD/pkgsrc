# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:34 jlam Exp $
#

DISTNAME=		pflogsumm-1.1.0
CATEGORIES=		sysutils mail
MASTER_SITES=		ftp://jimsun.linxnet.com/pub/postfix_contrib/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://jimsun.linxnet.com/postfix_contrib.html
COMMENT=		Produce summaries from Postfix syslog data

DEPENDS+=		p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		# defined
USE_PERL5=		# defined
INSTALLATION_DIRS=	man/man1 sbin

do-build:
	${SED} 's;/usr/bin/perl;${PERL5};' ${WRKSRC}/pflogsumm.pl \
	    > ${WRKSRC}/pflogsumm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pflogsumm ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pflogsumm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
