# $NetBSD: Makefile,v 1.10 2003/11/27 17:27:29 abs Exp $
#

DISTNAME=		tightvnc-1.2.9
WRKSRC=			${WRKDIR}/vnc_unixsrc
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		mycroft@NetBSD.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS=		vnc-[0-9]*

CRYPTO=			yes
USE_BUILDLINK2=		yes
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
USE_PERL5=		yes

USE_GNU_TOOLS+=		make

ALL_TARGET=		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc \
	    ${PREFIX}/bin/Xvnc
	${INSTALL_MAN} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc.man \
	    ${PREFIX}/man/man1/Xvnc.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect \
	    ${PREFIX}/bin/vncconnect
	${INSTALL_MAN} ${WRKSRC}/vncconnect/vncconnect.man \
	    ${PREFIX}/man/man1/vncconnect.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd \
	    ${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
	    ${PREFIX}/man/man1/vncpasswd.1
	${SED} -e 's|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${PERL5}|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${WRKSRC}/vncserver.man \
	    ${PREFIX}/man/man1/vncserver.1

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
