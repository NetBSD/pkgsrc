# $NetBSD: Makefile,v 1.46 2004/05/03 20:56:35 mrauch Exp $

DISTNAME=		openoffice-1.1.1
CATEGORIES=		misc
MASTER_SITES=		http://mirrors.isc.org/pub/openoffice/stable/1.1.1/\
			http://ftp.stardiv.de/pub/OpenOffice.org/stable/1.1.1/\
			ftp://ftp.ring.gr.jp/pub/misc/openoffice/stable/1.1.1/\
			http://openoffice.mirrors.ilisys.com.au/\
			http://www.ibiblio.org/pub/mirrors/openoffice/stable/1.1.1/\
			http://gd.tuwien.ac.at/office/openoffice/stable/1.1.1/\
			http://mirrors.sunsite.dk/openoffice/stable/1.1.1/\
			ftp://ftp.funet.fi/pub/mirrors/openoffice.org/stable/1.1.1/\
			http://ftp.leo.org/download/pub/comp/general/office/openoffice/stable/1.1.1/\
			ftp://ftp.saix.net/pub/OpenOffice.org/stable/1.1.1/\
			ftp://ftp.cyberfenix.net/pub/openoffice/stable/1.1.1/\
			ftp://ftp.mirror.ac.uk/sites/ny1.mirror.openoffice.org/stable/1.1.1/\
			http://mirror.pacific.net.au/openoffice/\
			ftp://ftp.ring.gr.jp/pub/misc/openoffice/stable/1.1.1/\
			ftp://ftp.kr.freebsd.org/pub/openoffice/stable/1.1.1/\
			http://www.fs.tum.de/~mrauch/OpenOffice/download/
DISTFILES=		OOo_1.1.1p1_source.tar.bz2
DISTFILES+=		gpc231.tar.Z
DISTFILES+=		ooo_addons_111.tar.bz2
SITES_gpc231.tar.Z= 	ftp://ftp.cs.man.ac.uk/pub/toby/gpc/
SITES_ooo_addons_111.tar.bz2=http://www.fs.tum.de/~mrauch/OpenOffice/download/\
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/mrauch/ 

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		{standalone-tcsh,tcsh}-[0-9]*:../../shells/tcsh
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

WRKSRC=			${WRKDIR}/oo_1.1.1_src/config_office
USE_BUILDLINK3=		yes
GCC_REQD=		3.0
USE_GCC_SHLIB=		yes

.include "../../mk/bsd.prefs.mk"

USE_X11=		# defined
USE_GNU_TOOLS+=		make
USE_PERL5=		build
PTHREAD_OPTS+=		require

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6Z[G-Z]*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--enable-mozilla --disable-java
CONFIGURE_ARGS+= 	--with-lang=ALL --with-dict=ALL

TEMP?=			${WRKSRC}
UNLIMIT_RESOURCES+=	datasize

post-extract:
# bring the two files from GPC into place
	${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
# bring the NetBSD mozilla zip files into place
	${CP} ${WRKDIR}/*.zip ${WRKSRC}/../moz/zipped/
	${CP} ${WRKDIR}/openintro_pkgsrc.bmp 				\
		${WRKSRC}/../offmgr/res/openintro.bmp

do-build:
	${_ULIMIT_CMD} tcsh -c "setenv PTHREAD_DIAGASSERT Ael && cd ${WRKSRC}/.. && ./bootstrap && source *.Set && dmake"

pre-install:
	${CP} ${WRKSRC}/../instsetoo/unxbsdi2.pro/01/normal/setup.ins 	\
		${WRKSRC}/../instsetoo/unxbsdi2.pro/01/normal/setup.ins.orig
	${SED}  -e "s|/usr/bin/soffice|${PREFIX}/bin/soffice.orig|g"	\
		-e "s|/usr/lib||g"					\
		<${WRKSRC}/../instsetoo/unxbsdi2.pro/01/normal/setup.ins.orig\
		>${WRKSRC}/../instsetoo/unxbsdi2.pro/01/normal/setup.ins

do-install:
	${SH} -c "cd ${WRKSRC}/../instsetoo/unxbsdi2.pro/01/normal; ./install --prefix=${PREFIX}"
	${RM} -f ${PREFIX}/bin/soffice.orig
	${SED}	-e "s|@@PREFIX@@|${PREFIX}|g"				\
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.for i in scalc sdraw simpress swriter
	${LN} -sf ${PREFIX}/OpenOffice.org1.1.1/program/$i ${PREFIX}/bin/$i
.endfor

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
