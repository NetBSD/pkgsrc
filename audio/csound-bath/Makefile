# $NetBSD: Makefile,v 1.4 2002/03/12 22:30:10 jmc Exp $
#

DISTNAME=		Csound4.12
PKGNAME=		csound-bath-4.12
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.maths.bath.ac.uk/pub/dream/newest/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		csound
CONFLICTS=		csound-4*

#pre-build:
#	${CHMOD} -R 644 ${WRKDIR}

#do-install:
#	${INSTALL_DATA_DIR} ${PREFIX}/share/csound
#	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/csound
#	${INSTALL_DATA} ${WRKSRC}/csound.txt ${PREFIX}/share/csound/
#	for i in `${FIND} ${WRKDIR} -type f -perm 755`; do \
#		${INSTALL_PROGRAM} $${i} ${PREFIX}/bin ; \
#	done

.include "../../mk/bsd.pkg.mk"
