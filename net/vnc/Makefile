# $NetBSD: Makefile,v 1.22 2001/09/27 23:18:33 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=		vnc-3.3.3r2
PKGNAME=		vnc-3.3.3.2
CATEGORIES=		net x11
MASTER_SITES=		ftp://ftp.uk.research.att.com/pub/vnc/dist/
DISTFILES=		vnc-3.3.3r2_unixsrc.tgz \
			vnc-3.3.2r2_doc.tgz

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

DEPENDS+=		vncviewer-[0-9]*:../../net/vncviewer

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

.include "../../mk/bsd.pkg.mk"
