# $NetBSD: Makefile,v 1.9 2003/03/28 21:14:16 wiz Exp $
#

DISTNAME=	tkdiff-3.05.tcl.txt
PKGNAME=	tkdiff-3.05
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.accurev.com/pub/free/tkdiff/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.accurev.com/free/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes
NO_CONFIGURE=	yes
CMDNAME=	tkdiff3

EXTRACT_CMD=	${CAT} ${DISTDIR}/${DISTNAME} |				\
		${SED} -e 's|^exec wish |exec wish |' |		\
		${TR} -d '\015' > ${WRKDIR}/${CMDNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${CMDNAME} ${LOCALBASE}/bin/${CMDNAME}

.include "../../mk/bsd.pkg.mk"
