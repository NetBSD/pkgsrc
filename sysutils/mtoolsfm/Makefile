# $NetBSD: Makefile,v 1.6 2003/07/13 13:53:20 wiz Exp $
#

DISTNAME=	MToolsFM-1.9-3
PKGNAME=	mtoolsfm-1.9.3
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/

MAINTAINER=	ben@wongs.net
HOMEPAGE=	http://www.core-coutainville.org/MToolsFM/
COMMENT=	Easy MS-DOS disk access without learning MS-DOS commands

DEPENDS+=	mtools>=3.9.7:../../sysutils/mtools

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-conffile=${PKG_SYSCONFDIR}/mtoolsfm.conf

post-extract:
	cd ${WRKSRC} && ${MV} MToolsFM.1 MToolsFM.1.in

pre-configure:
	cd ${WRKSRC} && ${SED} \
		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		< MToolsFM.1.in > MToolsFM.1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
