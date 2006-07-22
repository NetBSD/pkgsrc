# $NetBSD: Makefile,v 1.16 2006/07/22 19:21:11 abs Exp $

DISTNAME=       	vnc-4_1_2-unixsrc
PKGNAME=		vncviewer-4.1.2
CATEGORIES=		net x11
MASTER_SITES=   	http://www.realvnc.com/dist/

MAINTAINER=	 	riz@NetBSD.org
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_LANGUAGES=		c c++
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-zlib

# The distfile listed above is bogus, there is no direct link to download the
# file, so a special command must be used.  I lifted this from FreeBSD Ports.
DISTURL=http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.2&filetype=tar_gz&haveDetails=1
pre-fetch:
	${TEST} -f ${DISTDIR}/${DISTNAME}.tar.gz || \
	 (cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}.tar.gz ${DISTURL:Q})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man \
		${PREFIX}/man/man1/vncviewer.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
		${PREFIX}/man/man1/vncpasswd.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
