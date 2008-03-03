# $NetBSD: Makefile,v 1.18 2008/03/03 01:40:21 jlam Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

PKG_DESTDIR_SUPPORT=	destdir

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
		(${DESTDIR}cd ${PREFIX}/share/examples/geda && ${TAR} xvf -)
	${FIND} ${PREFIX}/share/examples/geda \
		\( -name \*Makefile\* -o -name config.log -o -name config.status \) \
		-exec ${RM} {} \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
