# $NetBSD: Makefile,v 1.55 2001/05/19 03:56:38 jlam Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=		kdenetwork-1.1.2
CATEGORIES=		net kde
MASTER_SITES=		ftp://ftp.us.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/ \
			ftp://ftp.de.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kde.org/
COMMENT=		Network modules for the KDE integrated X11 desktop

DEPENDS=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		uulib-0.5.13:../../converters/uulib
DEPENDS+=		kdesupport-1.1.2:../../converters/kdesupport
DEPENDS+=		kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=		yes
EVAL_PREFIX+=		QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=		"--datadir=${KDEBASEDIR}/share/kde" \
			"--with-qt-dir=${QT1DIR}/qt1"
CONFIGURE_ENV=  	KDEDIR=${KDEBASEDIR} \
			CPPFLAGS="${CPPFLAGS}" \
			CXXFLAGS="${CFLAGS}" \
			all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

GCC_VERSION!=   	gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
PLIST_SRC=		${PKGDIR}/PLIST.egcs
.else
PLIST_SRC=		${PKGDIR}/PLIST.gcc
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SRC=		${PKGDIR}/PLIST-SunOS
CPPFLAGS=		-I${LOCALBASE}/include
CFLAGS=			-I${LOCALBASE}/include
.elif ${OPSYS} == "NetBSD"
CPPFLAGS+=		-I${LOCALBASE}/include
CFLAGS+=		-I${LOCALBASE}/include
.endif

post-install:
.if (${GCC_VERSION:C/-.*$$//} != egcs)
	@${FIND} ${KDEBASEDIR}/share/kde/locale -name ksirc.mo | ${XARGS} ${RM}
.endif

.include "../../mk/bsd.pkg.mk"
