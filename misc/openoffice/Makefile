# $NetBSD: Makefile,v 1.3 2002/02/13 21:11:11 mrauch Exp $

DISTNAME=		openoffice-0.0.0.641
WRKSRC=			${WRKDIR}/oo_641_src/config_office
CATEGORIES=		misc
MASTER_SITES=		http://sf1.mirror.openoffice.org/641b/
DISTFILES=		oo_641_src.tar.bz2
DISTFILES+=		gpc231.tar.Z
DISTFILES+=		oo_moz_641.tar.gz
SITES_gpc231.tar.Z= 	ftp://ftp.cs.man.ac.uk/pub/toby/gpc/
SITES_oo_moz_641.tar.gz=ftp://ftp.netbsd.org/pub/NetBSD/misc/mrauch/

MAINTAINER=		mrauch@netbsd.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite

# OpenOffice requires gcc 2.95.2 or better,
# so for NetBSD<=1.5 we need the package lang/gcc.
GCC_VERSION!=		${CC} --version
.if ${GCC_VERSION}!="2.95.2" && ${GCC_VERSION}!="2.95.3"
.include "../../lang/gcc/Makefile.gcc"
.endif
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		gmake-[0-9]*:../../devel/gmake
BUILD_DEPENDS+=		tcsh-[0-9]*:../../shells/tcsh
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		stlport>=4.0nb1:../../devel/stlport
BUILD_DEPENDS+=		sun-jdk>=1.3.0:../../lang/sun-jdk13
.include "../../lang/perl5/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
BUILD_DEPENDS+=		pth>=1.4.0nb1:../../devel/pth
.include "../../mk/x11.buildlink.mk"

CONFLICTS=		staroffice-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5.3*-i386 NetBSD-1.5Z?-i386 \
			NetBSD-1.[6-9]*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--with-stlport4-home=${PREFIX}
CONFIGURE_ARGS+= 	--with-jdk-home=${PREFIX}/java

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
# The tar process on nas exits with an error code, extraction however is
# complete. Extract and repackage to make the build happy.
	${MV} ${WRKSRC}/../nas/download/nas-1.4.1.tar.gz		\
	    ${WRKSRC}/../nas/download/nas-1.4.1.tar.gz.orig
	tar -xzf ${WRKSRC}/../nas/download/nas-1.4.1.tar.gz.orig 	\
	    -C ${WRKDIR}
	tar -czf ${WRKSRC}/../nas/download/nas-1.4.1.tar.gz 		\
	    -C ${WRKDIR} nas-1.4.1

DISPLAY?=	#empty, if unset
checkforx:
.if ${DISPLAY}==""
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
	tcsh -c "setenv DISPLAY ${DISPLAY}; cd ${WRKSRC}/..&& 		\
		   ./bootstrap&& source *.Set&& dmake"
			
pre-install: checkforx
	${SH} -c "cd ${WRKSRC}/../instsetoo/*.pro/01/normal;		\
	    ${SED} -e 's#@@PREFIX@@#${PREFIX}#g'			\
		<${FILESDIR}/oo_setup.resp 				\
		>oo_setup.resp"

do-install:
	${SH} -c "cd ${WRKSRC}/../instsetoo/*.pro/01/normal;		\
		  TEMP=${WRKDIR}; export TEMP;				\
		  DISPLAY=${DISPLAY}; export DISPLAY;			\
		  ./setup -r:oo_setup.resp;				\
		  if ${TEST} -e ${PREFIX}/OpenOffice.org641/setup;	\
		    then ${TRUE};					\
		    else ${FALSE};					\
		  fi"
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g'				\
	    <${FILESDIR}/soffice >${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
	
.include "../../mk/bsd.pkg.mk"
