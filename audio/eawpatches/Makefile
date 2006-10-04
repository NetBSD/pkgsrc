# $NetBSD: Makefile,v 1.16 2006/10/04 20:44:18 wiz Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.stardate.bc.ca/eawpatches/
# http://www.george.ca/interests/eawpats12_full.tar.gz
EXTRACT_SUFX=	.rar

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.stardate.bc.ca/eawpatches/html/
# AWOL, ask http://www.sysbio.wustl.edu/pakrasi/people/ericw.php
COMMENT=	Eric A. Welsh' patches (audio samples) for TiMidity

BUILD_DEPENDS+=	unrar-[0-9]*:../../archivers/unrar

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/eawpatches
	cd ${PREFIX}/share/eawpatches && \
	unrar x -o+ -inul ${DISTDIR}/${DISTNAME}
	${CHMOD} 644 ${PREFIX}/share/eawpatches/*.* \
		${PREFIX}/share/eawpatches/*/*.*
	${SED}  -e "s@c:.timidity@${PREFIX}/share/eawpatches@" \
		-e "s@dir c:.eawpats@@" \
		< ${PREFIX}/share/eawpatches/timidity.cfg > /tmp/timidity.tmp
	${MV} /tmp/timidity.tmp ${PREFIX}/share/eawpatches/timidity.cfg

.include "../../mk/bsd.pkg.mk"
