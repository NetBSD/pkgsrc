# New packages collection makefile for: hugs
# Version required:	1.4
# Date created:		22-Mar-98
# Whom:			nathanw@mit.edu
#
# $NetBSD: Makefile,v 1.1 1998/04/03 21:14:22 tron Exp $

DISTNAME=	hugs-January1998-source
PKGNAME=	hugs-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://haskell.org/pub/haskell/hugs/January1998/ \
		ftp://ftp.cs.nott.ac.uk/pub/haskell/hugs/January1998/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nathanw@mit.edu

WRKSRC=		${WRKDIR}/hugs/src
GNU_CONFIGURE=	yes
ALL_TARGET=	default

# The hugs distribution puts configure and friends in a subdirectory 
# below the sources, and insists that configure be run from that directory,
# which is awkward for bsd.port.mk.
do-configure:
	@(cd ${WRKSRC}/unix && CC="${CC}" ac_cv_path_CC="${CC}" \
	    CFLAGS="${CFLAGS}" \
	    INSTALL="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

.include <bsd.port.mk>
