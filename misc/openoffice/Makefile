# $NetBSD: Makefile,v 1.22 2002/09/02 02:43:35 abs Exp $

DISTNAME=		openoffice-0.0.0.641
PKGREVISION=		1
WRKSRC=			${WRKDIR}/oo_641_src/config_office
CATEGORIES=		misc
MASTER_SITES=		http://sf1.mirror.openoffice.org/641b/		\
			http://www.fs.tum.de/~mrauch/OpenOffice/download/
DISTFILES=		oo_641_src.tar.bz2
DISTFILES+=		gpc231.tar.Z
DISTFILES+=		oo_moz_641.tar.gz
SITES_gpc231.tar.Z= 	ftp://ftp.cs.man.ac.uk/pub/toby/gpc/
SITES_oo_moz_641.tar.gz=ftp://ftp.netbsd.org/pub/NetBSD/misc/mrauch/

MAINTAINER=		mrauch@netbsd.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite

PTHREAD_OPTS+=		require

# OpenOffice requires gcc 2.95.2 or better,
# so for NetBSD<=1.5 we need the package lang/gcc.
GCC_VERSION!=		${CC} --version
.if ${GCC_VERSION}!="2.95.2" && ${GCC_VERSION}!="2.95.3"
.include "../../lang/gcc/Makefile.gcc"
.endif
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		gmake-[0-9]*:../../devel/gmake
BUILD_DEPENDS+=		{standalone-tcsh,tcsh}-[0-9]*:../../shells/tcsh
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		stlport>=4.0nb1:../../devel/stlport

USE_JAVA=		build
PKG_JVM=		sun-jdk13

CONFLICTS=		staroffice-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5.3*-i386 NetBSD-1.5Z?-i386 \
			NetBSD-1.[6-9]*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--with-stlport4-home=${PREFIX}
CONFIGURE_ARGS+= 	--with-jdk-home=${JAVA_HOME}

TEMP?=			${WRKSRC}

post-extract:
# bring the two files from GPC into place
	${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
# bring the NetBSD mozilla zip files into place
	${CP} ${WRKDIR}/*.zip ${WRKSRC}/../moz/zipped/
# convert \r\n-lineends in sablot-patch into unix-style \n first
	${PERL5} -p -i.save -e 's/\r\n/\n/' 				\
	    ${WRKSRC}/../sablot/Sablot-0.52.patch

.include "../../mk/bsd.prefs.mk"

DISPLAY?=	#empty, if unset
checkforx:
.if ${DISPLAY}=="" || ${DISPLAY_OK:!${X11BASE}/bin/xdpyinfo >/dev/null 2>&1 && echo YES || echo NO!} == "NO"
.if exists(${X11BASE}/bin/Xvfb)
	-${X11BASE}/bin/Xvfb :2 &
DISPLAY= ':2'
.else
	@${ECHO} "Error: Environment variable DISPLAY must be set"
	@${ECHO} "       and point to a connectible X server."
	@${FALSE}
.endif  #Xvfb
.endif  #DISPLAY

pre-build: checkforx

do-build:
	${_ULIMIT_CMD}tcsh -c "setenv DISPLAY '${DISPLAY}'; \
		cd ${WRKSRC}/.. && ./bootstrap && source *.Set && dmake"
			
pre-install: checkforx
	${SH} -c "cd ${WRKSRC}/../instsetoo/*.pro/01/normal;		\
	    ${SED} -e 's#@@PREFIX@@#${PREFIX}#g'			\
		<${FILESDIR}/oo_setup.resp 				\
		>oo_setup.resp"

do-install:
	-${SH} -c "cd ${WRKSRC}/../instsetoo/*.pro/01/normal;		\
		  TEMP=${WRKDIR}; export TEMP;				\
		  DISPLAY=${DISPLAY}; export DISPLAY;			\
		  ./setup -r:oo_setup.resp"
	@${SH} -c "if ! [ -x ${PREFIX}/OpenOffice.org641/setup ] ;	\
	           then ${ECHO} 'Installation was not successful.';	\
		   ${FALSE}; fi"
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g'				\
	    <${FILESDIR}/soffice >${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
	
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
