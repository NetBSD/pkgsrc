# $NetBSD: Makefile,v 1.37 2002/11/14 23:33:12 jlam Exp $

DISTNAME=	screen-3.9.13
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager

USE_BUILDLINK2=		# defined	
INFO_FILES=		screen.info
PLIST_SUBST=		DISTNAME=${DISTNAME}
TEXINFO_OVERRIDE=	YES

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

.include "../../mk/bsd.prefs.mk"

.if exists(${PKGDIR}/PLIST.${OPSYS})
PLIST_SRC=	${PKGDIR}/PLIST.${OPSYS}
.endif

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc			\
		${PREFIX}/share/examples/screen/screenrc
.if (${OPSYS} == SunOS)
	cd ${WRKSRC}/terminfo &&					\
	${SETENV} TERMINFO=${PREFIX}/share/lib/terminfo			\
		/usr/5bin/tic screeninfo.src
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
