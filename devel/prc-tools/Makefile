# $NetBSD: Makefile,v 1.15 2003/09/28 09:13:56 jlam Exp $
#

DISTNAME=	prc-tools-2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=prc-tools/}
DISTFILES=	${DISTNAME}.tar.gz ${DIST_BINUTILS}.tar.bz2
DISTFILES+=	${DIST_GCC}.tar.gz ${DIST_GDB}.tar.bz2

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://prc-tools.sourceforge.net/
COMMENT=	GNU tool chain for Palm cross development

DIST_BINUTILS=	binutils-2.12.1
DIST_GCC=	gcc-2.95.3
DIST_GDB=	gdb-5.0

SITES_${DIST_BINUTILS}.tar.bz2=${MASTER_SITE_GNU:=binutils/}
SITES_${DIST_BINUTILS}.tar.bz2+=http://prc-tools.sourceforge.net/misc/
SITES_${DIST_GCC}.tar.gz=${MASTER_SITE_GNU:=gcc/}
SITES_${DIST_GCC}.tar.gz+=http://prc-tools.sourceforge.net/misc/
# gdb-5.0 is no longer on gnu sites
#SITES_${DIST_GDB}.tar.bz2=${MASTER_SITE_GNU:=gdb/}
SITES_${DIST_GDB}.tar.bz2=http://prc-tools.sourceforge.net/misc/

# prc-tools-2.0 was split into multiple packages
CONFLICTS+=	prc-tools-base-[0-9]*
CONFLICTS+=	prc-tools-binutils-[0-9]*
CONFLICTS+=	prc-tools-gcc-[0-9]*
CONFLICTS+=	prc-tools-gdb-[0-9]*

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
AUTOCONF_REQD=	2.50
USE_MAKEINFO=	YES
INFO_FILES=	prc-tools.info

USE_PKGSRC_GCC=	# defined

#CONFIGURE_ARGS+=--target=m68k-palmos
CONFIGURE_ARGS+=--enable-targets=m68k-palmos,arm-palmos
CONFIGURE_ARGS+=--enable-languages=c,c++
CONFIGURE_ARGS+=--with-headers=${WRKSRC}/empty
CONFIGURE_ARGS+=--with-palmdev-prefix=${LOCALBASE}/share/palmdev
CONFIGURE_ARGS+=--disable-nls
#CONFIGURE_ARGS+=--enable-html-docs=${LOCALBASE}/share/doc/html/prc-tools

post-extract:
	${LN} -s ../${DIST_BINUTILS} ${WRKSRC}/binutils
	${LN} -s ../${DIST_GCC} ${WRKSRC}/gcc
	${LN} -s ../${DIST_GDB} ${WRKSRC}/gdb
	${MKDIR} ${WRKSRC}/empty

pre-patch:
	cd ${WRKDIR} \
		&& ${PATCH} --quiet -p0 < ${WRKSRC}/${DIST_BINUTILS}.palmos.diff
	cd ${WRKDIR} \
		&& ${PATCH} --quiet -p0 < ${WRKSRC}/${DIST_GCC}.palmos.diff
	cd ${WRKDIR} \
		&& ${PATCH} --quiet -p0 < ${WRKSRC}/${DIST_GDB}.palmos.diff

.include "../../mk/autoconf.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
