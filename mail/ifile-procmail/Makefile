# $NetBSD: Makefile,v 1.1.1.1 2002/12/13 09:46:55 salo Exp $
#

DISTNAME=	ifile.procmail-0.3
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	mail
MASTER_SITES=	http://Xtrmntr.org/ORBman/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://Xtrmntr.org/ORBman/ifile.procmail.html
COMMENT=	Set of scripts for ifile used in procmail environment

DEPENDS+=	ifile>=1.2.1:../../mail/ifile
DEPENDS+=	procmail>=3.22:../../mail/procmail

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != "NetBSD") && (${OPSYS} != "FreeBSD") && (${OPSYS} != "OpenBSD")
DEPENDS+=	mktemp>=1.4:../../sysutils/mktemp
.endif

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ifile
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ifile
	for f in `${LS} ${WRKSRC}/bin` ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$$f ${PREFIX}/bin ; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.new ${PREFIX}/share/doc/ifile/README
	${INSTALL_DATA} ${WRKSRC}/sample.procmailrc ${PREFIX}/share/examples/ifile

.include "../../mk/bsd.pkg.mk"
