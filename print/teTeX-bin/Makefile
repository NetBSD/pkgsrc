# $NetBSD: Makefile,v 1.36 2002/09/21 01:48:03 jlam Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-src-1.0.7
PKGNAME=	teTeX-bin-1.0.7
PKGREVISION=	2
WRKSRC=		${WRKDIR}/teTeX-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX-share>=1.0.2nb1:../teTeX-share
DEPENDS+=	dialog-0.6z:../../misc/dialog

CONFLICTS+=	omega-[0-9]*

DIST_SUBDIR=		teTeX
ALL_TARGET=		all
INSTALL_TARGET=		install strip

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
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

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--enable-auto-core
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
	### someone needs to adjust papersize to this:
	#texconfig dvips paper a4
	#texconfig xdvi a4
	texconfig font ro
	texconfig font vardir /var/spool/texfonts
	texconfig font options appendonlydir varfonts

.include "../../graphics/png/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
