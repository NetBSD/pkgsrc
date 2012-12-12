# $NetBSD: Makefile,v 1.15 2012/12/12 10:44:10 wiz Exp $
#

DISTNAME=	barcode-0.98
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=barcode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar.linux.it/software/barcode/
COMMENT=	Create bar codes as EPS (program and library)

GNU_CONFIGURE=	YES
MAKE_ENV+=	AWK=${AWK:Q}
INFO_FILES=	# PLIST

INSTALL_MAKE_FLAGS=					\
	BINDIR=${DESTDIR}${PREFIX}/bin			\
	INCDIR=${DESTDIR}${PREFIX}/include		\
	LIBDIR=${DESTDIR}${PREFIX}/lib			\
	INFODIR=${DESTDIR}${PREFIX}/${PKGINFODIR}	\
	MAN1DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1	\
	MAN3DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

# man/man1/barcode.1
CONFLICTS+=	xscreensaver<5.00

.include "../../mk/bsd.pkg.mk"
