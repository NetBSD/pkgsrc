# $NetBSD: Makefile,v 1.5 2004/01/20 12:19:43 agc Exp $
#

DISTNAME=	ifile.procmail-0.3
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	mail
MASTER_SITES=	http://Xtrmntr.org/ORBman/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://Xtrmntr.org/ORBman/ifile.procmail.html
COMMENT=	Set of scripts for ifile used in procmail environment

DEPENDS+=	ifile>=1.2.1:../../mail/ifile
DEPENDS+=	procmail>=3.22:../../mail/procmail

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.prefs.mk"

.if empty(OPSYS:M*BSD)
DEPENDS+=	mktemp>=1.4:../../sysutils/mktemp
.endif

NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ifile
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ifile
	for f in `${LS} ${WRKSRC}/bin` ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$$f ${PREFIX}/bin ; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.new ${PREFIX}/share/doc/ifile/README
	${INSTALL_DATA} ${WRKSRC}/sample.procmailrc ${PREFIX}/share/examples/ifile

.include "../../mk/bsd.pkg.mk"
