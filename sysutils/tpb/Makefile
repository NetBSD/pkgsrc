# $NetBSD: Makefile,v 1.20 2012/10/23 19:51:27 asau Exp $
#

DISTNAME=	tpb-0.6.1
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.nongnu.org/download/tpb/

MAINTAINER=	soren@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/tpb/
COMMENT=	Utility to enable the IBM ThinkPad(tm) special keys

ONLY_FOR_PLATFORM= *-*-i386

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/tpb
CONF_FILES=	${EGDIR}/tpbrc ${PKG_SYSCONFDIR}/tpbrc

INSTALLATION_DIRS+=	share/doc/tpb

post-install:
.for f in callback_example.sh nvram.txt
	${INSTALL_DATA}	${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/tpb
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
