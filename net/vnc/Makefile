# $NetBSD: Makefile,v 1.8 1999/09/02 21:29:31 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.3
CATEGORIES=		net x11
MASTER_SITES=   	http://www.uk.research.att.com/vnc/dist/
DISTFILES=		vnc-3.3.3_unixsrc.tgz \
			vnc-latest_doc.tgz

MAINTAINER=	 	packages@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/

USE_PERL5=		yes

# Is this for real? The code was developed in the UK,
# but the DES parts came from the USA in the first place.
RESTRICTED=		Contains cryptographic software

WRKSRC=			${WRKDIR}/vnc_unixsrc

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

ALL_TARGET=    		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED} -e 's|/usr/local/vnc/classes|${X11BASE}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
# The documentation comes with bogus ownerships; this is a little leaky security-wise
	${MKDIR} ${PREFIX}/share/doc/vnc
	(cd ${WRKDIR}/vnc_docs ; tar --exclude '*~' --exclude .lastinstall \
	--exclude makefile -cf - . ) | tar -xf - -C ${PREFIX}/share/doc/vnc
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc

.include "../../mk/bsd.pkg.mk"
