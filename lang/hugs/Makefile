# $NetBSD: Makefile,v 1.21 2002/04/09 02:59:14 markd Exp $

DISTNAME=	hugs98-Dec2001
PKGNAME=	hugs98-200112
WRKSRC=		${WRKDIR}/hugs98-Dec2001/src/unix
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

USE_BUILDLINK_ONLY=	# defined
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

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
