# $NetBSD: Makefile,v 1.4 1999/12/02 02:59:39 sakamoto Exp $
#

DISTNAME=	tkdiff-3.05.tcl.txt
PKGNAME=	tkdiff-3.05
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ede.com/pub/free/tkdiff/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ede.com/free/tkdiff/

DEPENDS+=	tk-8.0.5:../../x11/tk80

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes
CMDNAME=	tkdiff3

EXTRACT_CMD=	${CAT} ${DISTDIR}/${DISTNAME} |				\
		${SED} -e 's|^exec wish |exec wish8.0 |' |		\
		${TR} -d '\015' > ${WRKDIR}/${CMDNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${CMDNAME} ${LOCALBASE}/bin/${CMDNAME}

.include "../../mk/bsd.pkg.mk"
