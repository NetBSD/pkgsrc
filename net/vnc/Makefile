# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:21 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.2r2_unixsrc
PKGNAME=        	vnc-3.3.2
CATEGORIES=		net x11
MASTER_SITES=   	http://www.orl.co.uk/vnc/dist/
DISTFILES=		vnc-3.3.2r2_unixsrc.tgz \
			vnc-3.3.2_doc.tgz

MAINTAINER=	 	packages@netbsd.org
HOMEPAGE=		http://www.orl.co.uk/vnc/

IGNOREFILES=		${DISTFILES}

USE_PERL5=		yes

EXTRACT_ONLY=		vnc-3.3.2r2_unixsrc.tgz

# Is this for real? The code was developed in the UK,
# but the DES parts came from the USA in the first place.
RESTRICTED=		Contains cryptographic software

NO_WRKSUBDIR=		yes

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

ALL_TARGET=    		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKDIR}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKDIR}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED} -e 's|/usr/local/vnc/classes|${X11BASE}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		< ${WRKDIR}/vncserver \
		> ${WRKDIR}/vncserver.local
	${INSTALL_SCRIPT} ${WRKDIR}/vncserver.local ${PREFIX}/bin/vncserver
# The documentation comes with bogus ownerships; this is a little leaky security-wise
	${MKDIR} ${PREFIX}/share/doc/vnc
	tar --exclude '*~' --exclude .lastinstall --exclude makefile \
	    -xzf ${DISTDIR}/vnc-3.3.2_doc.tgz -C ${PREFIX}/share/doc/vnc
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc

.include "../../mk/bsd.pkg.mk"
