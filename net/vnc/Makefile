# $NetBSD: Makefile,v 1.14 2000/11/10 16:57:24 abs Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=		vnc-3.3.3r1
PKGNAME=		vnc-3.3.3.1
CATEGORIES=		net x11
MASTER_SITES=		http://www.uk.research.att.com/vnc/dist/
DISTFILES=		vnc-3.3.3r1_unixsrc.tgz \
			vnc-latest_doc.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/

DEPENDS+=		vncviewer:../../net/vncviewer

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
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED} -e 's|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${PERL5}|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
	${MKDIR} ${PREFIX}/share/doc/vnc
	cd ${WRKDIR}/vnc_docs; \
	${INSTALL_DATA} *.GIF *.css *.gif *.jpg *.htm *.html *.pdf *.xml \
	  ${PREFIX}/share/doc/vnc

.include "../../mk/bsd.pkg.mk"
