# $NetBSD: Makefile,v 1.21 2020/03/20 11:58:22 nia Exp $
#

DISTNAME=	MToolsFM-1.9-3
PKGNAME=	mtoolsfm-1.9.3
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mtoolsfm.sourceforge.net/
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
.include "../../mk/bsd.pkg.mk"
