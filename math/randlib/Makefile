# $NetBSD: Makefile,v 1.16 2011/12/18 17:11:34 marino Exp $

DISTNAME=	randlib.c-1.3
PKGNAME=	randlib-1.3
CATEGORIES=	math
MASTER_SITES=	# ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://biostatistics.mdanderson.org/SoftwareDownload/SingleSoftware.aspx?Software_Id=27
COMMENT=	Library of C Routines for Random Number Generation

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/randlib.c/src

MAKE_ENV+=	LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	include lib share/doc/randlib share/examples/randlib
MAKE_FLAGS+=		MKPROFILE=yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/../README ${WRKSRC}/../doc/* \
		${DESTDIR}${PREFIX}/share/doc/randlib
	${INSTALL_DATA} ${WRKSRC}/../test/* ${DESTDIR}${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/randlib.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
