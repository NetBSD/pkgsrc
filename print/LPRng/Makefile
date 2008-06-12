# $NetBSD: Makefile,v 1.22 2008/06/12 02:14:42 joerg Exp $

DISTNAME=	LPRng-3.6.28
PKGREVISION=	2
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	"meta-package" for LPRng, Enhanced Printer Spooler

DEPENDS+=	LPRng-core-3.8.28{,nb*}:../../print/LPRng-core
DEPENDS+=	LPRng-doc-3.6.13:../../print/LPRng-doc

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
PLIST_SRC=		# empty (meta-package)

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
