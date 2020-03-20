# $NetBSD: Makefile,v 1.42 2020/03/20 11:58:21 nia Exp $
#

DISTNAME=	idesk-0.7.5
PKGREVISION=	15
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=idesk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://idesk.sourceforge.net/
COMMENT=	Lightweight desktop icons handler
LICENSE=	modified-bsd

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
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
