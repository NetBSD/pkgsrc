# $NetBSD: Makefile,v 1.68 2003/12/29 02:02:38 kristerw Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:54 asami Exp
#

DISTNAME=		kdenetwork-1.1.2
PKGREVISION=		3
CATEGORIES=		net kde
MASTER_SITES=		${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.kde.org/
COMMENT=		Network modules for the KDE integrated X11 desktop

DEPENDS=		gdbm>=1.8.3:../../databases/gdbm
DEPENDS+=		uulib>=0.5.13:../../converters/uulib
DEPENDS+=		kdesupport-1.1.2:../../converters/kdesupport
DEPENDS+=		kdebase-1.1.2nb4:../../x11/kdebase

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=		yes
EVAL_PREFIX+=		QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=		"--datadir=${KDEBASEDIR}/share/kde" \
			"--with-qt-dir=${QT1DIR}/qt1"
CONFIGURE_ENV=  	KDEDIR=${KDEBASEDIR} \
			CXXFLAGS="${CFLAGS}" \
			all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=		KDE_LDFLAGS
KDE_LDFLAGS=		-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../mk/bsd.prefs.mk"

.if !empty(CC_VERSION:Megcs*)
PLIST_SRC=		${PKGDIR}/PLIST.egcs
.else
PLIST_SRC=		${PKGDIR}/PLIST.gcc
.endif

.if ${OPSYS} == "SunOS"
PLIST_SRC=		${PKGDIR}/PLIST-SunOS
CPPFLAGS=		-I${LOCALBASE}/include
CFLAGS=			-I${LOCALBASE}/include
.elif ${OPSYS} == "NetBSD"
CPPFLAGS+=		-I${LOCALBASE}/include
CFLAGS+=		-I${LOCALBASE}/include
.endif

post-install:
.if empty(CC_VERSION:Megcs*)
	@${FIND} ${KDEBASEDIR}/share/kde/locale -name ksirc.mo | ${XARGS} ${RM}
.endif

.include "../../mk/bsd.pkg.mk"
