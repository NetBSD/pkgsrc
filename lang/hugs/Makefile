# $NetBSD: Makefile,v 1.32 2005/11/03 22:35:53 rillig Exp $

DISTNAME=	hugs98-Dec2001
PKGNAME=	hugs98-200112
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src/unix
CONFIGURE_ARGS+=	--with-readline
BUILD_DIRS=		src
BUILD_TARGET=		default

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# Trick it into not checking if symbols have leading underscores,
# since the dlcompat layer expects you to not be that clever.
CONFIGURE_ENV+=		ac_cv_header_nlist_h=no
.endif

INSTALLATION_DIRS=	man/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
