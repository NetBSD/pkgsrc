# $NetBSD: Makefile,v 1.4 2008/01/18 05:06:41 tnn Exp $

DISTNAME=		koverartist-0.5
PKGREVISION=		3
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.kde-apps.org/content/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.kde-apps.org/content/show.php?content=38195
COMMENT=		CD/DVD case designer

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/koverartist

DISTURL=${MASTER_SITES}download.php?content=38195&id=1
pre-fetch:
	${TEST} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} || \
	(cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}${EXTRACT_SUFX} ${DISTURL:Q})

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
