# $NetBSD: Makefile,v 1.12 2006/10/15 11:52:28 markd Exp $
#

DISTNAME=	barcode-0.98
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK=${AWK:Q}
INFO_FILES=	# PLIST

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}		\
			MAN1DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man1		\
			MAN3DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man3

# man/man1/barcode.1
CONFLICTS+=	xscreensaver<5.00

.include "../../mk/bsd.pkg.mk"
