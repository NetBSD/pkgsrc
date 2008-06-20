# $NetBSD: Makefile,v 1.20 2008/06/20 01:09:08 joerg Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		find gmake tar

CHECK_INTERPRETER_SKIP+=	share/examples/*

pre-install:
	${RM} -f ${WRKSRC}/config.status.overridden
	${RM} -f ${WRKSRC}/configure.lineno

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/geda
	cd ${WRKSRC} && ${TAR} cf - . | \
		(cd ${DESTDIR}${PREFIX}/share/examples/geda && ${TAR} xvf -)
	${FIND} ${DESTDIR}${PREFIX}/share/examples/geda \
		\( -name \*Makefile\* -o -name config.log -o -name config.status \) \
		-exec ${RM} {} \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
