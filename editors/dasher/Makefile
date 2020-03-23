# $NetBSD: Makefile,v 1.103 2020/03/23 12:25:38 nia Exp $

DISTNAME=	dasher-5.0.0.b20200225
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=dasher-project/}
GITHUB_TAG=	e03b0dbf1f1132e83645ff78c92efd63fca5a812

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inference.phy.cam.ac.uk/dasher/
COMMENT=	Easy typing without using keyboard
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	yelp-tools-[0-9]*:../../textproc/yelp-tools

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config

pre-configure:
	# tries to invoke git for something, probably fetching the ref
	${ECHO} "true" > ${WRKSRC}/build-aux/mkversion
	cd ${WRKSRC} && autoreconf -fi

.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
