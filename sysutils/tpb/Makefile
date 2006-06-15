# $NetBSD: Makefile,v 1.14 2006/06/15 15:18:03 joerg Exp $
#

DISTNAME=	tpb-0.6.1
PKGREVISION=	4
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tpb
.for f in callback_example.sh nvram.txt
	${INSTALL_DATA}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/tpb
.endfor

.include "../../x11/xosd/buildlink3.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
