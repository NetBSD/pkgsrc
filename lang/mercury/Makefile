# $NetBSD: Makefile,v 1.8 2003/05/02 17:48:28 jtb Exp $

DISTNAME=		mercury-compiler-0.11.0
PKGNAME=		mercury-0.11.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.mercury.cs.mu.oz.au/pub/mercury/ \
			${MASTER_SITE_SUNSITE:=devel/lang/mercury/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.mu.oz.au/mercury/
COMMENT=		modern logic/functional programming language

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNU_READLINE=	yes	# rl_prep_term_function

INFO_FILES=		mercury.info

# Some of the scripts test CC and use special settings for gcc.
CONFIGURE_ENV+=		CC=gcc

MAKE_ENV+=		READLINE_PREFIX=${BUILDLINK_PREFIX.readline}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} INSTALL_PREFIX=${WRKSRC}/tmp \
			MERCURY_COMPILER=${WRKSRC}/tmp/lib/mercury/bin/${MACHINE_GNU_PLATFORM}/mercury_compile \
		install

do-install:
	cd ${WRKSRC}/tmp && ${PAX} -rw . ${PREFIX}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mercury
	${FIND} ${WRKSRC} -type d -name "CVS" | ${XARGS} ${RM} -fr
	${FIND} ${WRKSRC} -type f -name ".cvsignore" | ${XARGS} ${RM} -f
	cd ${WRKSRC}/samples && ${PAX} -rw . ${PREFIX}/share/examples/mercury

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
