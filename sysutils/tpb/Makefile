# $NetBSD: Makefile,v 1.4 2004/02/19 17:49:57 jmmv Exp $
#

DISTNAME=	tpb-0.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.nongnu.org/download/tpb/

MAINTAINER=	soren@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/tpb/
COMMENT=	Utility to enable the IBM ThinkPad(tm) special keys

ONLY_FOR_PLATFORM= *-*-i386

USE_X11=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/tpb
CONF_FILES=	${EGDIR}/tpbrc ${PKG_SYSCONFDIR}/tpbrc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tpb
.for f in callback_example.sh nvram.txt
	${INSTALL_DATA}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/tpb
.endfor

.include "../../x11/xosd/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
