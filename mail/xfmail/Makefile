# $NetBSD: Makefile,v 1.26 2002/11/01 16:34:39 wiz Exp $

DISTNAME=		xfmail-1.4.7
PKGREVISION=		2
CATEGORIES=		mail x11
MASTER_SITES=		ftp://xfmail.ufies.org/pub/xfmail/release/1.4.7/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://xfmail.slappy.org/
COMMENT=		Xforms based mail application for Unix operating systems

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

RESTRICTED=		"Selling this software requires permission of the authors."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

AUTOCONF_REQD=		2.13
USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

pre-configure:
	cd ${WRKSRC} && ( ${LN} -sf config/configure.in . && ${LN} -sf config/acconfig.h . )
	cd ${WRKSRC} && ( ${AUTOHEADER} && ${AUTOCONF} )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
