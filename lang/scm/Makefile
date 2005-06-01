# $NetBSD: Makefile,v 1.11 2005/06/01 18:02:59 jlam Exp $
#

DISTNAME=	scm5d9
PKGNAME=	scm-5d9
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM.html
COMMENT=	Portable scheme interpreter

DEPENDS+=	slib>=3.1.1:../../devel/slib

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/scm

BUILD_TARGET=	scmlit libscm.a
INSTALL_TARGET=	install installlib

INFO_FILES=	scm.info hobbit.info Xlibscm.info

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${FILESDIR}/require.scm > ${WRKSRC}/require.scm

post-build:
	${CAT} ${FILESDIR}/buildscm.sh \
		| ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		| ${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		> ${WRKSRC}/buildscm.sh
	cd ${WRKSRC} && ${SH} ./buildscm.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/slibcat ${PREFIX}/share/scm
	for f in ${INFO_FILES}; do					\
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/info;		\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
