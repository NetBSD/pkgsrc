# $NetBSD: Makefile,v 1.4 2004/10/03 00:15:02 tv Exp $
#

DISTNAME=	scm5d8
PKGNAME=	scm-5d8
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
EXTRACT_SUFX=	.zip

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM.html
COMMENT=	Portable scheme interpreter

DEPENDS+=	slib>=2.4.6:../../devel/slib

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
USE_X11=	# defined

WRKSRC=		${WRKDIR}/scm

ALL_TARGET=	scmlit libscm.a
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
.include "../../mk/bsd.pkg.mk"
