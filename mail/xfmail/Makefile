# $NetBSD: Makefile,v 1.22 2001/12/20 09:48:03 tron Exp $

DISTNAME=		xfmail-1.4.7
CATEGORIES=		mail x11
MASTER_SITES=		ftp://xfmail.ufies.org/pub/xfmail/release/1.4.7/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://xfmail.slappy.org/
COMMENT=		Xforms based mail application for Unix operating systems

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

RESTRICTED=		"Selling this software requires permission of the authors."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

pre-configure:
	cd ${WRKSRC} && ( ${LN} -sf config/configure.in . && ${LN} -sf config/acconfig.h . )
	cd ${WRKSRC} && ( ${LOCALBASE}/bin/autoheader && ${LOCALBASE}/bin/autoconf )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/xforms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
