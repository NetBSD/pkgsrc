# $NetBSD: Makefile,v 1.16 2003/09/28 09:13:57 jlam Exp $

DISTNAME=		mercury-compiler-0.11.0
PKGNAME=		mercury-0.11.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.mercury.cs.mu.oz.au/pub/mercury/ \
			${MASTER_SITE_SUNSITE:=devel/lang/mercury/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.mu.oz.au/mercury/
COMMENT=		Modern logic/functional programming language

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNU_READLINE=	yes	# rl_prep_term_function

INFO_FILES=		mercury.info mercury_faq.info mercury_library.info
INFO_FILES+=		mercury_ref.info mercury_trans_guide.info

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
.include "../../mk/bsd.pkg.mk"
