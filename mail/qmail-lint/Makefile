# $NetBSD: Makefile,v 1.2 2002/01/21 19:07:39 zuntum Exp $
#

DISTNAME=	qmail-lint-0.55
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://qmail.obeer.com/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	examine the qmail configuration to see if any common errors exist

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=		${WRKDIR}

USE_PERL5=	yes
REPLACE_PERL=	${DISTNAME}
NO_BUILD=	yes

post-patch:
	${SED} "s,/var/qmail,${QMAILDIR}," ${WRKSRC}/${DISTNAME}	\
		> ${WRKSRC}/${DISTNAME}.done
	${MV} ${WRKSRC}/${DISTNAME}.done ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/qmail-lint

.include "../../mk/bsd.pkg.mk"
