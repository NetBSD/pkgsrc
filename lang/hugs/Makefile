# $NetBSD: Makefile,v 1.24 2004/01/20 12:19:16 agc Exp $

DISTNAME=	hugs98-Dec2001
PKGNAME=	hugs98-200112
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

WRKSRC=			${WRKDIR}/hugs98-Dec2001/src/unix
USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
ALL_TARGET=		default

do-build:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_MAN} ${WRKSRC}/../../docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
