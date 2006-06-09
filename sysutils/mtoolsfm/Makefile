# $NetBSD: Makefile,v 1.14 2006/06/09 09:50:37 joerg Exp $
#

DISTNAME=	MToolsFM-1.9-3
PKGNAME=	mtoolsfm-1.9.3
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.core-coutainville.org/MToolsFM/
COMMENT=	Easy MS-DOS disk access without learning MS-DOS commands

DEPENDS+=	mtools>=3.9.7:../../sysutils/mtools

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--with-conffile=${PKG_SYSCONFDIR}/mtoolsfm.conf

post-extract:
	cd ${WRKSRC} && ${MV} MToolsFM.1 MToolsFM.1.in

pre-configure:
	cd ${WRKSRC} && ${SED} \
		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		< MToolsFM.1.in > MToolsFM.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
