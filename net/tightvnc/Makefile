# $NetBSD: Makefile,v 1.3 2002/02/12 07:11:29 martti Exp $
#

DISTNAME=		tightvnc-1.2.2
PKGNAME=		tightvnc-1.2.2
CATEGORIES=		net x11
MASTER_SITES=		http://prdownloads.sourceforge.net/vnc-tight/ \
			ftp://ftp.uk.research.att.com/pub/vnc/dist/
DISTFILES=		tightvnc-1.2.2_unixsrc.tar.bz2 \
			vnc-3.3.2r2_doc.tgz

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS=		vnc-[0-9]*

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes
USE_PERL5=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc

ALL_TARGET=		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED} -e 's|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${PERL5}|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vnc
	cd ${WRKDIR}; \
	${INSTALL_DATA} *.GIF *.css *.gif *.jpg *.htm *.html *.pdf \
	  ${PREFIX}/share/doc/vnc

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
