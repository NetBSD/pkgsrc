# $NetBSD: Makefile,v 1.17 2001/02/26 22:32:09 tron Exp $
#

DISTNAME=		xfmail-1.4.7
CATEGORIES=		mail x11
MASTER_SITES=		ftp://xfmail.ufies.org/pub/xfmail/release/1.4.7/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://xfmail.slappy.org/
COMMENT=		Xforms based mail application for Unix operating systems

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		xforms>=0.88nb1:../../x11/xforms
DEPENDS+=		glib-*:../../devel/glib

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

RESTRICTED=		"Selling this software requires permission of the authors."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES

pre-configure:
	cd ${WRKSRC} && ( ${LN} -sf config/configure.in . && ${LN} -sf config/acconfig.h . )
	cd ${WRKSRC} && ( ${LOCALBASE}/bin/autoheader && ${LOCALBASE}/bin/autoconf )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../mk/bsd.pkg.mk"
