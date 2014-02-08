# $NetBSD: Makefile,v 1.25 2014/02/08 23:39:55 wiedi Exp $
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
# Thus, 5e3 -> 5.5.3
#
# Do not forget to update InitXXX.scm in files/buildscm.scm

DISTNAME=	scm5e3
PKGNAME=	scm-5.5.3
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM
COMMENT=	Portable scheme interpreter

DEPENDS+=	slib>=3.1.1:../../devel/slib

WRKSRC=		${WRKDIR}/scm
EVAL_PREFIX+=	SLIB_PREFIX=slib
INFO_FILES=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl

SCM_MODULES+=	sc2 ramap dynl edline gsubr ioext posix record rgx socket
SCM_MODULES+=	unix  continue scm scmmain findexec script time repl scl eval
SCM_MODULES+=	sys subr debug unif rope unexelf
COMPILED_INITS+=init_edline

.include "options.mk"

SRCS=		${SCM_MODULES:=.c}
OBJS=		${SCM_MODULES:=.o}

BUILD_TARGET=	scmlit libscm.a
INSTALL_TARGET=	install installlib

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/

INSTALLATION_DIRS=	${PKGINFODIR} share/scm

.include "../../mk/readline.buildlink3.mk"

post-extract:
	${SED} -e "s|@SLIB_PREFIX@|"${SLIB_PREFIX:Q}"|g"		\
		${FILESDIR}/require.scm > ${WRKSRC}/require.scm
	${SED} -e "s|@PREFIX@|"${PREFIX:Q}"|g"				\
		-e "s|@COMPILED_INITS@|${COMPILED_INITS:=();}|g"	\
		${FILESDIR}/buildscm.sh  > ${WRKSRC}/buildscm.sh

post-build:
	cd ${WRKSRC} && env ${MAKE_ENV} LIBS=${LIBS:Q} \
		SRCS=${SRCS:Q} OBJS=${OBJS:Q} \
		${SH} ./buildscm.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/slibcat ${DESTDIR}${PREFIX}/share/scm
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
