# $NetBSD: Makefile,v 1.18 2007/02/22 19:01:21 wiz Exp $
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

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM.html
COMMENT=	Portable scheme interpreter

DEPENDS+=	slib>=3.1.1:../../devel/slib

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/scm
EVAL_PREFIX+=	SLIB_PREFIX=slib
INFO_FILES=	# PLIST

BUILD_TARGET=	scmlit libscm.a
INSTALL_TARGET=	install installlib

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} mandir=${PREFIX:Q}/${PKGMANDIR:Q}/

INSTALLATION_DIRS=	${PKGINFODIR} share/scm

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

do-configure:
	${SED} -e "s|@SLIB_PREFIX@|"${SLIB_PREFIX:Q}"|g"		\
		${FILESDIR}/require.scm > ${WRKSRC}/require.scm
	${SED}	-e "s|@CC@|"${CC:Q}"|g"					\
		-e "s|@CFLAGS@|"${CFLAGS:Q}"|g"				\
		-e "s|@PREFIX@|"${PREFIX:Q}"|g"				\
		${FILESDIR}/buildscm.sh > ${WRKSRC}/buildscm.sh

post-build:
	cd ${WRKSRC} && ${SH} ./buildscm.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/slibcat ${PREFIX}/share/scm
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
