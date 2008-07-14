# $NetBSD: Makefile,v 1.7 2008/07/14 12:56:07 joerg Exp $

DISTNAME=	ja-FreeWnn-server-1.10
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese/Chinese/Korean input method (Japanese server)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ja-FreeWnn-server-bin>=1.10nb4:../../inputmethod/ja-freewnn-server-bin
DEPENDS+=	ja-FreeWnn-dict>=1.10nb1:../../inputmethod/ja-freewnn-dict

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
NO_CHECKSUM=	YES
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
