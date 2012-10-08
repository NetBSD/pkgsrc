# $NetBSD: Makefile,v 1.10 2012/10/08 12:19:13 asau Exp $
#

DISTNAME=	ifile.procmail-0.3
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://Xtrmntr.org/ORBman/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://Xtrmntr.org/ORBman/ifile.procmail.html
COMMENT=	Set of scripts for ifile used in procmail environment

DEPENDS+=	ifile>=1.2.1:../../mail/ifile
DEPENDS+=	procmail>=3.22:../../mail/procmail

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	ksh:run mktemp:run

REPLACE_KSH+=	bin/ifile.*

NO_BUILD=	YES

INSTALLATION_DIRS=	bin share/doc/ifile share/examples/ifile

do-install:
	for f in `${LS} ${WRKSRC}/bin` ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$$f ${DESTDIR}${PREFIX}/bin ; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.new \
		${DESTDIR}${PREFIX}/share/doc/ifile/README
	${INSTALL_DATA} ${WRKSRC}/sample.procmailrc \
		${DESTDIR}${PREFIX}/share/examples/ifile

.include "../../mk/bsd.pkg.mk"
