# $NetBSD: Makefile,v 1.21 2009/05/12 08:42:37 hasso Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
PKGREVISION=	1
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

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

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
