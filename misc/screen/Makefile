# $NetBSD: Makefile,v 1.30.2.1 2002/06/23 18:54:17 jlam Exp $

DISTNAME=	screen-3.9.11
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager

GNU_CONFIGURE=		yes
INFO_FILES=		screen.info
PLIST_SUBST=		DISTNAME=${DISTNAME}
USE_BUILDLINK_ONLY=	yes
TEXINFO_OVERRIDE=	YES

CONFIGURE_ARGS+=--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == SunOS)
PLIST_SRC=	${PKGDIR}/PLIST.SunOS
.endif

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/share/examples/screen/screenrc
.if (${OPSYS} == SunOS)
	cd ${WRKSRC}/terminfo && \
	${SETENV} TERMINFO=${PREFIX}/share/lib/terminfo \
	  /usr/5bin/tic screeninfo.src
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
