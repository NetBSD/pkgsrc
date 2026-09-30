# $NetBSD: Makefile,v 1.26 2026/09/30 02:05:07 brook Exp $
#

DISTNAME=		pflogsumm-1.2.0
CATEGORIES=		sysutils mail
MASTER_SITES=		https://athena.linxnet.com/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://athena.linxnet.com/postfix_contrib.html
COMMENT=		Produce summaries from Postfix syslog data
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

.include "../../mk/bsd.prefs.mk"

NO_BUILD=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin share/doc/pflogsumm

REPLACE_PERL+=		pffrombyto
REPLACE_PERL+=		pflogsumm
REPLACE_PERL+=		pftobyfrom

do-install:
.for f in pflogsumm pffrombyto pftobyfrom
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for doc in ChangeLog README ToDo pflogsumm-faq.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/pflogsumm
.endfor

.include "../../mk/bsd.pkg.mk"
