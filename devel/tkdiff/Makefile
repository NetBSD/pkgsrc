# $NetBSD: Makefile,v 1.2 1999/08/10 11:44:45 agc Exp $
#

DISTNAME=	tkdiff-3.03m.tcl.txt
PKGNAME=	tkdiff-3.03m
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
	${RM} -f ${LOCALBASE}/bin/tkdiff
	${LN} -s ${LOCALBASE}/bin/${CMDNAME} ${LOCALBASE}/bin/tkdiff

.include "../../mk/bsd.pkg.mk"
