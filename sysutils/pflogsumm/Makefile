# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:04 wiz Exp $
#

DISTNAME=		pflogsumm-1.1.5
PKGREVISION=		#
PKGREVISION=		3
CATEGORIES=		sysutils mail
MASTER_SITES=		https://jimsun.linxnet.com/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jimsun.linxnet.com/postfix_contrib.html
COMMENT=		Produce summaries from Postfix syslog data
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin share/doc/pflogsumm

do-build:
	${SED} 's;/usr/bin/perl;${PERL5};' ${WRKSRC}/pflogsumm.pl \
	    > ${WRKSRC}/pflogsumm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pflogsumm ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pflogsumm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for doc in ChangeLog README ToDo pflogsumm-faq.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/pflogsumm
.endfor


.include "../../mk/bsd.pkg.mk"
