# $NetBSD: Makefile,v 1.44 2013/06/11 19:34:14 asau Exp $

DISTNAME=		mercury-srcdist-13.05.1-beta-2013-05-28
PKGNAME=		mercury-13.05.1beta
CATEGORIES=		lang
MASTER_SITES=		http://dl.mercurylang.org/release/ \
			ftp://ftp.mercury.cs.mu.oz.au/pub/mercury/ \
			http://www.mercury.cs.mu.oz.au/download/files/ \
			${MASTER_SITE_SUNSITE:=devel/lang/mercury/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mercurylang.org/
COMMENT=		Modern logic/functional programming language

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pax bison flex
USE_TOOLS+=		perl # ?
USE_GNU_READLINE=	yes # rl_prep_term_function
INFO_FILES=		yes

# Some of the scripts test CC and use special settings for gcc.
CONFIGURE_ENV+=		CC=gcc

CONFIGURE_ENV+=		HOSTNAMECMD=${TOOLS_HOSTNAME_CMD:Q}
USE_TOOLS+=		hostname

MAKE_ENV+=		READLINE_PREFIX=${BUILDLINK_PREFIX.readline}

INSTALL_PREFIX=		${WRKSRC}/tmp
BUILD_MAKE_FLAGS=	${MAKE_FLAGS}
BUILD_MAKE_FLAGS+=	INSTALL_PREFIX=${INSTALL_PREFIX:Q}
BUILD_MAKE_FLAGS+=	INSTALL_INFO_DIR=${INSTALL_PREFIX:Q}/${PKGINFODIR:Q}
BUILD_MAKE_FLAGS+=	INSTALL_MAN_DIR=${INSTALL_PREFIX:Q}/${PKGMANDIR:Q}
BUILD_MAKE_FLAGS+=	MERCURY_COMPILER=${INSTALL_PREFIX:Q}/bin/mercury_compile
#BUILD_MAKE_FLAGS+=	PARALLEL=$(MAKE_JOBS:D-j$(MAKE_JOBS))

CHECK_PORTABILITY_SKIP+=	boehm_gc/configure
CHECK_INTERPRETER_SKIP+=	lib/mercury/reconf/scripts/mtags.in

post-patch:
	${TOUCH} \
		${WRKSRC}/library/table_builtin.date3		\
		${WRKSRC}/library/table_builtin.date		\
		${WRKSRC}/library/table_builtin.optdate		\
		${WRKSRC}/library/table_builtin.trans_opt_date	\
		${WRKSRC}/library/table_builtin.c_date

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} install

do-install:
	cd ${WRKSRC}/tmp && pax -rw . ${DESTDIR}${PREFIX}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mercury
	${FIND} ${WRKSRC} -type d -name "CVS" -print | ${XARGS} ${RM} -fr
	${FIND} ${WRKSRC} -type f -name ".cvsignore" -print | ${XARGS} ${RM} -f
	cd ${WRKSRC}/samples && \
	pax -rw . ${DESTDIR}${PREFIX}/share/examples/mercury

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
