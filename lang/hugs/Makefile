# $NetBSD: Makefile,v 1.15 2001/05/22 06:54:05 jlam Exp $

DISTNAME=	hugs98-Feb2000
PKGNAME=	hugs98-200002
CATEGORIES=	lang
MASTER_SITES=	ftp://www.cse.ogi.edu/pub/pacsoft/hugs/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

WRKSRC=			${WRKDIR}/hugs98/src/unix
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
ALL_TARGET=		default

# Don't link against ncurses; linking against termcap will do.
CONFIGURE_ENV+=		ac_cv_lib_ncurses_main=no

# Hugs' build doesn't require the readline headers, only the readline library.
# The only function it uses is readline().
#
.include "../../devel/readline/Makefile.readline"

LDFLAGS+=		-L${WRKLIBDIR}

pre-configure: link-readline-libs

do-build:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_MAN} ${WRKSRC}/../../docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../mk/bsd.pkg.mk"
