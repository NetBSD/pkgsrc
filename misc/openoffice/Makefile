# $NetBSD: Makefile,v 1.54 2004/10/03 00:13:00 tv Exp $

DISTNAME=		openoffice-1.1.1
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/1.1.1/}
DISTFILES=		OOo_1.1.1p1_source.tar.bz2
DISTFILES+=		gpc231.tar.Z
DISTFILES+=		ooo_addons_111p1.tar.bz2
SITES_gpc231.tar.Z= 	ftp://ftp.cs.man.ac.uk/pub/toby/gpc/
SITES_ooo_addons_111p1.tar.bz2=http://www.fs.tum.de/~mrauch/OpenOffice/download/\
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/mrauch/
DIST_SUBDIR=		${PKGNAME_NOREV}

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

PLIST_SRC+=		PLIST.common
PLIST_SUBST+=		OPENOFFICE_DLLSUFFIX=${OPENOFFICE_DLLSUFFIX}
.if exists(${PKGDIR}/PLIST.${OPSYS})
PLIST_SRC+=             ${PKGDIR}/PLIST.${OPSYS}
. endif

post-extract:
# bring the two files from GPC into place
	${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
# bring the NetBSD mozilla zip files into place
	${CP} ${WRKDIR}/moz/*.zip ${WRKSRC}/../moz/zipped/
	${CP} ${WRKDIR}/openintro_pkgsrc.bmp 				\
		${WRKSRC}/../offmgr/res/openintro.bmp
# bring the localized helpcontent into place
	${MKDIR} ${WRKSRC}/../helpcontent/${OPENOFFICE_OUTPATH}.pro/bin
	-${CP} ${WRKDIR}/*.zip ${WRKSRC}/../helpcontent/${OPENOFFICE_OUTPATH}.pro/bin/

do-build:
	${_ULIMIT_CMD} tcsh -c "setenv PTHREAD_DIAGASSERT Ael && cd ${WRKSRC}/.. && ./bootstrap && source ${OPENOFFICE_SETFILE}Env.Set && dmake"

post-build:
	@${ECHO_MSG} "Please ignore the warning above that the project gtk"
	@${ECHO_MSG} "could not be found. Your build completed successfully."

pre-install:
	${CP} ${WRKSRC}/../instsetoo/${OPENOFFICE_OUTPATH}.pro/${OPENOFFICE_LANGCODE}/normal/setup.ins 	\
		${WRKSRC}/../instsetoo/${OPENOFFICE_OUTPATH}.pro/${OPENOFFICE_LANGCODE}/normal/setup.ins.orig
	${SED}  -e "s|/usr/bin/soffice|${PREFIX}/bin/soffice.orig|g"	\
		-e "s|/usr/lib||g"					\
		<${WRKSRC}/../instsetoo/${OPENOFFICE_OUTPATH}.pro/${OPENOFFICE_LANGCODE}/normal/setup.ins.orig\
		>${WRKSRC}/../instsetoo/${OPENOFFICE_OUTPATH}.pro/${OPENOFFICE_LANGCODE}/normal/setup.ins

do-install:
	${SH} -c "cd ${WRKSRC}/../instsetoo/${OPENOFFICE_OUTPATH}.pro/${OPENOFFICE_LANGCODE}/normal; ./install --prefix=${PREFIX}"
	${RM} -f ${PREFIX}/bin/soffice.orig
	${SED}	-e "s|@@PREFIX@@|${PREFIX}|g"				\
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.for i in scalc sdraw simpress swriter
	${LN} -sf ${PREFIX}/OpenOffice.org1.1.1/program/$i ${PREFIX}/bin/$i
.endfor

# everything specific to your OS/Arch goes into its own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

# everything related to i18n is in a separate file
.include "Makefile.i18n"

PLIST_SRC+=		PLIST.common_end

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
