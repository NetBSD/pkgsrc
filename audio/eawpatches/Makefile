# $NetBSD: Makefile,v 1.13 2004/11/27 16:48:56 wiz Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
CATEGORIES=	audio
MASTER_SITES=	http://www.stardate.bc.ca/eawpatches/
EXTRACT_SUFX=	.rar

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.stardate.bc.ca/eawpatches/html/
COMMENT=	Eric A. Welsh' patches (audio samples) for TiMidity

BUILD_DEPENDS=  unrar-[0-9]*:../../archivers/unrar

CONFLICTS=	guspatches-[0-9]*

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/timidity
	cd ${PREFIX}/share/timidity && \
	unrar x -o+ -inul ${DISTDIR}/${DISTNAME}
	${CHMOD} 644 ${PREFIX}/share/timidity/*.* \
		${PREFIX}/share/timidity/*/*.*
	${SED}  -e "s@c:.timidity@${PREFIX}/share/timidity@" \
		-e "s@dir c:.eawpats@@" \
		< ${PREFIX}/share/timidity/timidity.cfg > /tmp/timidity.tmp
	${MV} /tmp/timidity.tmp ${PREFIX}/share/timidity/timidity.cfg

.include "../../mk/bsd.pkg.mk"
