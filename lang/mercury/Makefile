# $NetBSD: Makefile,v 1.22 2004/10/03 00:15:01 tv Exp $

DISTNAME=		mercury-compiler-0.11.0
PKGNAME=		mercury-0.11.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.mercury.cs.mu.oz.au/pub/mercury/ \
			${MASTER_SITE_SUNSITE:=devel/lang/mercury/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.mu.oz.au/mercury/
COMMENT=		Modern logic/functional programming language

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	yes	# rl_prep_term_function

INFO_FILES=		mercury.info mercury_faq.info mercury_library.info
INFO_FILES+=		mercury_ref.info mercury_trans_guide.info
INFO_FILES+=		mercury_user_guide.info

# Some of the scripts test CC and use special settings for gcc.
CONFIGURE_ENV+=		CC=gcc

MAKE_ENV+=		READLINE_PREFIX=${BUILDLINK_PREFIX.readline}

post-patch:
	${TOUCH} \
		${WRKSRC}/library/table_builtin.date3		\
		${WRKSRC}/library/table_builtin.date		\
		${WRKSRC}/library/table_builtin.optdate		\
		${WRKSRC}/library/table_builtin.trans_opt_date	\
		${WRKSRC}/library/table_builtin.c_date

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} INSTALL_PREFIX=${WRKSRC}/tmp \
			MERCURY_COMPILER=${WRKSRC}/tmp/lib/mercury/bin/${MACHINE_GNU_PLATFORM}/mercury_compile \
		install

do-install:
	cd ${WRKSRC}/tmp && ${PAX} -rw . ${PREFIX}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mercury
	${FIND} ${WRKSRC} -type d -name "CVS" -print | ${XARGS} ${RM} -fr
	${FIND} ${WRKSRC} -type f -name ".cvsignore" -print | ${XARGS} ${RM} -f
	cd ${WRKSRC}/samples && ${PAX} -rw . ${PREFIX}/share/examples/mercury

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
