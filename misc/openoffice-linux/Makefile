# $NetBSD: Makefile,v 1.1.1.1 2003/01/22 21:57:25 mrauch Exp $

DISTNAME=		OOo_1.0.2_LinuxIntel_install
PKGNAME=		openoffice-linux-1.0.2
CATEGORIES=		misc
MASTER_SITES=		http://sf1.mirror.openoffice.org/stable/1.0.2/	\
			http://www.fs.tum.de/~mrauch/OpenOffice/download/

MAINTAINER=		mrauch@netbsd.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

NO_CONFIGURE=           # defined
WRKSRC=			${WRKDIR}/install/

CONFLICTS=		staroffice-[0-9]* openoffice-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386 NetBSD-[2-9]*-i386

TEMP?=			${WRKSRC}

.include "../../mk/bsd.prefs.mk"

DISPLAY?=       #empty, if unset
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

pre-install: checkforx
	${SH} -c "cd ${WRKSRC};						\
	    ${SED} -e 's#@@PREFIX@@#${PREFIX}#g'			\
		<${FILESDIR}/oo_setup.resp				\
		>oo_setup.resp"

do-install:
	-${SH} -c "cd ${WRKSRC};					\
		  TEMP=${WRKSRC}; export TEMP;				\
		  DISPLAY=${DISPLAY}; export DISPLAY;			\
		  ./setup -r:oo_setup.resp"
	@${SH} -c "if ! [ -x ${PREFIX}/OpenOffice.org1.0.2/setup ] ;	\
		   then ${ECHO} 'Installation was not successful.';	\
		   ${FALSE}; fi"
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g'				\
	    <${FILESDIR}/soffice >${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
	${PATCH} -t -s ${PREFIX}/OpenOffice.org1.0.2/program/soffice	\
		<${FILESDIR}/soffice.test.patch

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif

