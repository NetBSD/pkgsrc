# $NetBSD: Makefile,v 1.32 2001/11/29 01:12:45 hubertf Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-src-1.0.7
PKGNAME=	teTeX-bin-1.0.7
PKGREVISION=	1
WRKSRC=		${WRKDIR}/teTeX-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX-share>=1.0.2nb1:../teTeX-share
DEPENDS+=	dialog-0.6z:../../misc/dialog
DEPENDS+=	libwww>=5.3.2nb1:../../www/libwww
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

CONFLICTS+=	omega-[0-9]*

ALL_TARGET=	all
INSTALL_TARGET=	install strip
DIST_SUBDIR=	teTeX
USE_GMAKE=	yes
USE_X11=	yes
CFLAGS+=	-Dunix
GNU_CONFIGURE=	yes
INFO_FILES=	latex.info dvips.info web2c.info kpathsea.info
CONFIGURE_ARGS+=--without-texinfo \
		--without-dialog \
		--disable-multiplatform \
		--enable-ipc \
		--with-epsfwin \
		--with-hp2627win \
		--with-mftalkwin \
		--with-x11 \
		--with-libwww-config=${LOCALBASE}/bin/libwww-config \
		--with-system-pnglib \
		--with-pnglib-libdir=${LOCALBASE}/lib \
		--with-pnglib-include=${LOCALBASE}/include \
		--with-system-zlib
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=--enable-auto-core \
		--with-zlib-libdir=/usr/lib \
		--with-zlib-include=/usr/include
.else
CONFIGURE_ARGS+= --with-zlib-libdir=${LOCALBASE}/lib \
		--with-zlib-include=${LOCALBASE}/include
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-install:
	@${RM} ${PREFIX}/share/texmf/web2c/*.log
	### someone needs to adjust papersize to this:
	#texconfig dvips paper a4
	#texconfig xdvi a4
	texconfig font ro
	texconfig font vardir /var/spool/texfonts
	texconfig font options appendonlydir varfonts

.include "../../mk/bsd.pkg.mk"
