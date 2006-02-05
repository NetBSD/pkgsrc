# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:48 joerg Exp $
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
# Thus, 5e1 -> 5.5.1
#
# Do not forget to update InitXXX.scm in files/buildscm.scm

DISTNAME=	scm5e1
PKGNAME=	scm-5.5.1
PKGREVISION=	1
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
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' \
		< ${FILESDIR}/require.scm > ${WRKSRC}/require.scm

post-build:
	${CAT} ${FILESDIR}/buildscm.sh \
		| ${SED} -e 's|@CC@|${CC}|g' \
		| ${SED} -e 's|@CFLAGS@|${CFLAGS}|g' \
		| ${SED} -e 's|@PREFIX@|${PREFIX}|g' \
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
