# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 17:17:16 wiz Exp $
#

DISTNAME=		Csound4.12
PKGNAME=		csound-bath-4.12
NO_WRKSUBDIR=		yes
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.maths.bath.ac.uk/pub/dream/newest/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

LICENSE=		csound-license
NO_SRC_ON_CDROM=	"no for-fee-redistribution"
NO_BIN_ON_CDROM=	${NO_SRC_ON_CDROM}

DIST_SUBDIR=		csound
MAKE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
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
