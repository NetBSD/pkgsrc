# $NetBSD: Makefile,v 1.7 2001/05/05 19:51:14 jlam Exp $
#

DISTNAME=	tkdiff-3.05.tcl.txt
PKGNAME=	tkdiff-3.05
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ede.com/pub/free/tkdiff/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ede.com/free/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes
CMDNAME=	tkdiff3

EXTRACT_CMD=	${CAT} ${DISTDIR}/${DISTNAME} |				\
		${SED} -e 's|^exec wish |exec wish |' |		\
		${TR} -d '\015' > ${WRKDIR}/${CMDNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${CMDNAME} ${LOCALBASE}/bin/${CMDNAME}

.include "../../mk/bsd.pkg.mk"
