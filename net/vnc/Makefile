# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.1_unixsrc
PKGNAME=        	vnc-3.1.1
CATEGORIES=		net
MASTER_SITES=   	http://www.orl.co.uk/vnc/dist/
DISTFILES=		vnc-3.3.1_unixsrc.tgz \
			vnc-3.3.1_doc.tgz
IGNOREFILES=		${DISTFILES}

MAINTAINER=	 	msmith@FreeBSD.ORG

USE_PERL5=		YES

EXTRACT_ONLY=		vnc-3.3.1_unixsrc.tgz

# Is this for real? The code was developed in the UK,
# but the DES parts came from the USA in the first place.
RESTRICTED=		Contains cryptographic software

NO_WRKSUBDIR=		YES

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

ALL_TARGET=    		world

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKDIR}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKDIR}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED} -e 's|/usr/local/vnc/classes|${X11BASE}/share/vnc/classes|g' \
		-e 's|/usr/local/bin/perl|${LOCALBASE}/bin/perl|g' \
		< ${WRKDIR}/vncserver \
		> ${WRKDIR}/vncserver.local
	${INSTALL_SCRIPT} ${WRKDIR}/vncserver.local ${PREFIX}/bin/vncserver
# The documentation comes with bogus ownerships; this is a little leaky security-wise
	${MKDIR} ${PREFIX}/share/doc/vnc
	tar -C ${PREFIX}/share/doc/vnc -xzf ${DISTDIR}/vnc-3.3.1_doc.tgz
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc

.include "../../mk/bsd.pkg.mk"
