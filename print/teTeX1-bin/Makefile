# $NetBSD: Makefile,v 1.8 2004/04/25 21:23:34 snj Exp $

DISTNAME=	teTeX-src-1.0.7
PKGNAME=	teTeX-bin-1.0.7
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX-share-1.0.[2-9]*:../teTeX1-share
DEPENDS+=	dialog-0.6z*:../../misc/dialog

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

WRKSRC=			${WRKDIR}/teTeX-1.0
DIST_SUBDIR=		teTeX
ALL_TARGET=		all
INSTALL_TARGET=		install strip

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GCC_SHLIB=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
CFLAGS+=		-Dunix

INFO_FILES=		latex.info dvips.info web2c.info kpathsea.info

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-texinfo
CONFIGURE_ARGS+=	--without-dialog
CONFIGURE_ARGS+=	--disable-multiplatform
CONFIGURE_ARGS+=	--enable-ipc
CONFIGURE_ARGS+=	--with-epsfwin
CONFIGURE_ARGS+=	--with-hp2627win
CONFIGURE_ARGS+=	--with-mftalkwin
CONFIGURE_ARGS+=	--with-x11
CONFIGURE_ARGS+=	--with-libwww-config=${LOCALBASE}/bin/libwww-config
CONFIGURE_ARGS+=	--with-system-pnglib
CONFIGURE_ARGS+=	--with-pnglib-include=${BUILDLINK_PREFIX.png}/include
CONFIGURE_ARGS+=	--with-pnglib-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-include=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib

.include "../../mk/bsd.prefs.mk"
# sysutils/coreutils installs a 'readlink' program, so conflict with it if
# GNU_PROGRAM_PREFIX == ''
.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		coreutils-[0-9]*
.endif

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--enable-auto-core
.endif

.if ${OPSYS} == "Darwin" && ${OS_VERSION:R} == "6"
# Darwin 6.x's default (3.1ish) g++ has a bug that breaks the xpdf build
CXX=			g++2
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

TEXFONTSDIR=		/var/spool/texfonts
OWN_DIRS=		${TEXFONTSDIR}
OWN_DIRS_PERMS=		${TEXFONTSDIR}/pk ${ROOT_USER} ${ROOT_GROUP} 1777
OWN_DIRS_PERMS+=	${TEXFONTSDIR}/source ${ROOT_USER} ${ROOT_GROUP} 1777
OWN_DIRS_PERMS+=	${TEXFONTSDIR}/tfm ${ROOT_USER} ${ROOT_GROUP} 1777

post-install:
	@${RM} ${PREFIX}/share/texmf/web2c/*.log
.if defined(PAPERSIZE)
	${LOCALBASE}/bin/texconfig dvips paper ${PAPERSIZE:tl}
.  if ${PAPERSIZE} == "Letter"
	${LOCALBASE}/bin/texconfig xdvi us
.  else
	${LOCALBASE}/bin/texconfig xdvi ${PAPERSIZE:tl}
.  endif
.endif
	${LOCALBASE}/bin/texconfig font ro
	${LOCALBASE}/bin/texconfig font vardir /var/spool/texfonts
	${LOCALBASE}/bin/texconfig font options appendonlydir varfonts

.include "../../graphics/png/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
