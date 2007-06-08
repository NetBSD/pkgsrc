# $NetBSD: Makefile,v 1.16 2007/06/08 23:52:02 dmcmahill Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		find gmake tar

CHECK_INTERPRETER_SKIP+=	share/examples/*

pre-install:
	${RM} -f ${WRKSRC}/config.status.overridden
	${RM} -f ${WRKSRC}/configure.lineno

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && ${TAR} cf - . | \
		(cd ${PREFIX}/share/examples/geda && ${TAR} xvf -)
	${FIND} ${PREFIX}/share/examples/geda \
		\( -name \*Makefile\* -o -name config.log -o -name config.status \) \
		-exec ${RM} {} \;
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
