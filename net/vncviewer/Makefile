# $NetBSD: Makefile,v 1.24 2008/06/20 01:09:32 joerg Exp $

DISTNAME=		vnc-4_1_2-unixsrc
PKGNAME=		vncviewer-4.1.2
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=		http://www.realvnc.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		tightvncviewer-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_LANGUAGES=		c c++
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-zlib

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# The distfile listed above is bogus, there is no direct link to download the
# file, so a special command must be used.  I lifted this from FreeBSD Ports.
DISTURL=http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.2&filetype=tar_gz&haveDetails=1
pre-fetch:
	${TEST} -f ${DISTDIR}/${DISTNAME}.tar.gz || \
	 (cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}.tar.gz ${DISTURL:Q})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${DESTDIR}${PREFIX}/bin/vncviewer
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncviewer.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${DESTDIR}${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
