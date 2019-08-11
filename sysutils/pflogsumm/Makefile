# $NetBSD: Makefile,v 1.21 2019/08/11 13:23:16 wiz Exp $
#

DISTNAME=		pflogsumm-1.1.3
PKGREVISION=		1
CATEGORIES=		sysutils mail
MASTER_SITES=		ftp://jimsun.linxnet.com/pub/postfix_contrib/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://jimsun.linxnet.com/postfix_contrib.html
COMMENT=		Produce summaries from Postfix syslog data

DEPENDS+=		p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

do-build:
	${SED} 's;/usr/bin/perl;${PERL5};' ${WRKSRC}/pflogsumm.pl \
	    > ${WRKSRC}/pflogsumm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pflogsumm ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pflogsumm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
