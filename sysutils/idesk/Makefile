# $NetBSD: Makefile,v 1.31 2012/07/15 08:22:54 wiz Exp $
#

DISTNAME=	idesk-0.7.5
PKGREVISION=	8
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=idesk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://idesk.sourceforge.net/
COMMENT=	Lightweight desktop icons handler
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-libsn

SUBST_CLASSES+=		lnkpath
SUBST_STAGE.lnkpath=	pre-configure
SUBST_FILES.lnkpath=	examples/default.lnk
SUBST_SED.lnkpath=	-e 's|/usr/local/share|${PREFIX}/share|g'

INSTALLATION_DIRS+=	share/doc/idesk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/idesk

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
