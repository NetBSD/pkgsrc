# $NetBSD: Makefile,v 1.12 2003/12/24 09:53:47 jmmv Exp $
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
	if [ ! -d ${PREFIX}/share/timidity ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/share/timidity; \
	fi
	cd ${PREFIX}/share/timidity && \
	unrar x -o+ -inul ${DISTDIR}/${DISTNAME}
	${CHMOD} 644 ${PREFIX}/share/timidity/*.* \
		${PREFIX}/share/timidity/*/*.*
	${SED}  -e "s@c:.timidity@${PREFIX}/share/timidity@" \
		-e "s@dir c:.eawpats@@" \
		< ${PREFIX}/share/timidity/timidity.cfg > /tmp/timidity.tmp
	${MV} /tmp/timidity.tmp ${PREFIX}/share/timidity/timidity.cfg

.include "../../mk/bsd.pkg.mk"
