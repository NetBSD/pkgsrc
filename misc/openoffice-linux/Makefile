# $NetBSD: Makefile,v 1.4.2.1 2003/03/02 10:55:44 agc Exp $

DISTNAME=		OOo_1.0.2_LinuxIntel_install
PKGNAME=		openoffice-linux-1.0.2
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		http://sf1.mirror.openoffice.org/stable/1.0.2/	\
			http://www.fs.tum.de/~mrauch/OpenOffice/download/

MAINTAINER=		mrauch@netbsd.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

NO_CONFIGURE=           yes
WRKSRC=			${WRKDIR}/install

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386 NetBSD-[2-9]*-i386

TEMP?=			${WRKSRC}

.include "../../mk/bsd.prefs.mk"

DISPLAY?=       # empty, if unset
checkforx:
.if ${DISPLAY}=="" || ${DISPLAY_OK:!${X11BASE}/bin/xdpyinfo >/dev/null 2>&1 && ${ECHO} YES || ${ECHO} NO!} == "NO"
.  if exists(${X11BASE}/bin/Xvfb)
	-${X11BASE}/bin/Xvfb :2 &
DISPLAY= ':2'
.  else
	@${ECHO} "Error: Environment variable DISPLAY must be set"
	@${ECHO} "       and point to a connectible X server."
	@${FALSE}
.  endif  #Xvfb
.endif  #DISPLAY

do-build:

.if ${OPSYS} == "NetBSD"
USE_PKGINSTALL=         yes
SUPPORT_FILES=          /dev/null /emul/linux/etc/mtab
.endif

pre-install: checkforx
	${SED}	-e "s|@@PREFIX@@|${PREFIX}|g"				\
		< ${FILESDIR}/oo_setup.resp > ${WRKSRC}/oo_setup.resp
.     if ${OPSYS}=="NetBSD" && !exists(/emul/linux/etc/mtab)
	${CP} /dev/null /emul/linux/etc/mtab
.     endif

do-install:
	-${SH} -c "cd ${WRKSRC};					\
		  TEMP=${WRKSRC}; export TEMP;				\
		  DISPLAY=${DISPLAY}; export DISPLAY;			\
		  ./setup -r:oo_setup.resp"
	@if [ ! -x ${PREFIX}/OpenOffice.org1.0.2/setup ]; then		\
		${ECHO} "Installation was not successful.";		\
		${FALSE};						\
	fi
	${SED}	-e "s|@@PREFIX@@|${PREFIX}|g"				\
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
	${PATCH} -t -s ${PREFIX}/OpenOffice.org1.0.2/program/soffice	\
		< ${FILESDIR}/soffice.test.patch

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif
