# $NetBSD: Makefile,v 1.71 2008/07/14 12:56:01 joerg Exp $

DISTNAME=	kdevelop-3.5.1
CATEGORIES=	devel kde meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	Integrated Development Environment for Unix/X11/KDE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	c-cpp-reference>=2.0.2nb4:../../devel/c-cpp-reference
DEPENDS+=	kdbg>=1.2.5:../../devel/kdbg

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
