# $NetBSD: Makefile,v 1.28 1999/03/05 22:13:56 tron Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=	kdenetwork-1.1
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	uulib-0.5.13:../../converters/uulib
DEPENDS+=	kdesupport-1.1:../../converters/kdesupport
DEPENDS+=	kdebase-1.1:../../x11/kdebase

NOT_FOR_ARCHS=	alpha	# LP64/ELF problems

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_FLAGS=	--cplusplus --install-la
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

GCC_VERSION!=   gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
PLIST_SRC=	${PKGDIR}/PLIST.egcs
.else
PLIST_SRC=	${PKGDIR}/PLIST.gcc
.endif

post-install:
.if (${GCC_VERSION:C/-.*$$//} != egcs)
		@find ${PREFIX}/share/kde/locale -name ksirc.mo | xargs ${RM}
.endif

.include "../../mk/bsd.pkg.mk"
