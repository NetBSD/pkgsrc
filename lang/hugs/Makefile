# $NetBSD: Makefile,v 1.30 2005/06/16 06:58:00 jlam Exp $

DISTNAME=	hugs98-Dec2001
PKGNAME=	hugs98-200112
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

WRKSRC=			${WRKDIR}/hugs98-Dec2001/src/unix
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
BUILD_TARGET=		default

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# Trick it into not checking if symbols have leading underscores,
# since the dlcompat layer expects you to not be that clever.
CONFIGURE_ENV+=		ac_cv_header_nlist_h=no
.endif

INSTALLATION_DIRS=	man/man1

do-build:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}

do-install:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_MAN} ${WRKSRC}/../../docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
