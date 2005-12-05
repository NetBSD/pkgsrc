# $NetBSD: Makefile,v 1.15 2005/12/05 20:49:47 rillig Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.stardate.bc.ca/eawpatches/
EXTRACT_SUFX=	.rar

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.stardate.bc.ca/eawpatches/html/
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
