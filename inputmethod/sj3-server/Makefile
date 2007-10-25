# $NetBSD: Makefile,v 1.9 2007/10/25 22:00:47 jlam Exp $

DISTNAME=	sj3-server-2.0.1.20
PKGREVISION=	3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	SJ3 Japanese input method server

DEPENDS+=	sj3-server-bin>=2.0.1.20nb6:../../inputmethod/sj3-server-bin
DEPENDS+=	sj3-dict>=2.0.1.20nb3:../../inputmethod/sj3-dict

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_CHECKSUM=	YES
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
