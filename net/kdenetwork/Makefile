# $NetBSD: Makefile,v 1.41 2000/03/28 00:12:31 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=		kdenetwork-1.1.2
CATEGORIES=		net kde
MASTER_SITES=		ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
			ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kde.org/

DEPENDS=		gdbm-1.7.3:../../databases/gdbm
DEPENDS+=		uulib-0.5.13:../../converters/uulib
DEPENDS+=		kdesupport-1.1.2:../../converters/kdesupport
DEPENDS+=		kdebase-1.1.2:../../x11/kdebase

NOT_FOR_PLATFORM=	*-*-alpha	# LP64/ELF problems

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_FLAGS=		--cplusplus --install-la
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		"--datadir=${PREFIX}/share/kde" \
			"--with-qt-dir=${X11BASE}/qt1" 
CONFIGURE_ENV=  	KDEDIR=${PREFIX} \
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
	@${FIND} ${PREFIX}/share/kde/locale -name ksirc.mo | xargs ${RM}
.endif

.include "../../mk/bsd.pkg.mk"
