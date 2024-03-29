# $NetBSD: Makefile,v 1.9 2022/12/06 00:27:33 gutteridge Exp $

DISTNAME=		libreoffice5-bin	# overridden below
PKGNAME=		libreoffice5-bin-${OO_RELEASE}
CATEGORIES=		misc

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.libreoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)
LICENSE=		gnu-lgpl-v3

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*
CONFLICTS+=		libreoffice3-bin-[0-9]*
CONFLICTS+=		libreoffice4-bin-[0-9]*
CONFLICTS+=		libreoffice6-bin-[0-9]*

OO_VER=			5
OO_BASEVER=		${OO_VER}.4
OO_RELEASE=		${OO_BASEVER}.7
OO_RELEASEV=		${OO_RELEASE}.2
PLIST_SUBST+=		VER=${OO_VER:Q} BASEVER=${OO_BASEVER:Q}
MESSAGE_SUBST+=		VER=${OO_VER:Q}
FILES_SUBST+=		VER=${OO_VER:Q}

TEMP?=			${WRKSRC}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
BUILD_DIRS=		# empty

PLIST_SRC=		${PKGDIR}/PLIST.proglinks
PLIST_SRC+=		${WRKDIR}/PLIST
PLIST_SRC+=		${PKGDIR}/PLIST.dirs

EMUL_PLATFORMS=		linux-i386 linux-x86_64
#EMUL_PLATFORMS+=	solaris-i386 solaris-sparc
EMUL_MODULES.linux=	cups dbus dbus-glib fontconfig freetype2 glx
EMUL_MODULES.linux+=	gstreamer gtk2 krb5 locale png x11
EMUL_REQD=		suse>=11.3

EMUL_PKG_FMT=		rpm
RPMFILES=		${WRKSRC}/RPMS/*.rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

USE_TOOLS+=	patch uniq

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		LibreOffice_${OO_RELEASEV}_Linux_x86_rpm
WRKSRC=			${WRKDIR}/LibreOffice_${OO_RELEASEV}_Linux_x86_rpm
MASTER_SITES=		https://downloadarchive.documentfoundation.org/libreoffice/old/${OO_RELEASEV}/rpm/x86/
.elif ${EMUL_PLATFORM} == "linux-x86_64"
DISTNAME=		LibreOffice_${OO_RELEASEV}_Linux_x86-64_rpm
WRKSRC=			${WRKDIR}/LibreOffice_${OO_RELEASEV}_Linux_x86-64_rpm
MASTER_SITES=		https://downloadarchive.documentfoundation.org/libreoffice/old/${OO_RELEASEV}/rpm/x86_64/
.endif

.include "options.mk"

INSTALLATION_DIRS=	bin share/applications
DESKTOP_FILESDIR=	${.CURDIR}/../../misc/libreoffice5-bin/files

do-install:
	${UNIQ} ${RPM2PKG_PLIST} | \
		${SED} -e 's,^@exec mkdir -m 755 -p %D/,@pkgdir,' > ${WRKDIR}/PLIST
	${RM} -f ${DESTDIR}${PREFIX}/bin/soffice
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		-e "s|@@JAVA_HOME@@|${PKG_JAVA_HOME}|g" \
		-e "s|@@OO_BASEVER@@|${OO_BASEVER}|g" \
		< ${FILESDIR}/soffice > ${DESTDIR}${PREFIX}/bin/soffice
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/soffice
	${INSTALL_DATA} ${DESKTOP_FILESDIR}/*.desktop ${DESTDIR}${PREFIX}/share/applications
.for i in sbase scalc sdraw simpress smath swriter
	${LN} -sf ../opt/libreoffice${OO_BASEVER}/program/${i} ${DESTDIR}${PREFIX}/bin/${i}
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
