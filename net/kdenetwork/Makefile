# $NetBSD: Makefile,v 1.24 1999/01/30 23:18:53 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=	kdenetwork-1.0
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	uulib-0.5.13:../../converters/uulib
DEPENDS+=	kdesupport-1.0:../../converters/kdesupport
DEPENDS+=	kdebase-1.0:../../x11/kdebase

CONFLICTS=	kdenetwork-2.1b kdenetwork-3.1b kdenetwork-4.1b

NOT_FOR_ARCHS=	alpha	# LP64/ELF problems

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
