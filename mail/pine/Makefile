# $NetBSD: Makefile,v 1.23 1998/09/22 06:11:38 garbled Exp $
# FreeBSD Id: Makefile,v 1.21 1997/03/26 02:12:07 ache Exp
#

DISTNAME=       pine4.02
PKGNAME=        pine-4.02
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

NOT_FOR_ARCHS=	alpha	#LP64 problems

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.washington.edu/pine/

# This pkg doesn't build pico or libpico; the pico pkg does that part.
DEPENDS=	pico-3.2:../../editors/pico

CONFLICTS=	pine-3.96 pine-4.00

do-configure:
	${CP} -f ${WRKSRC}/pine/osdep/os-neb.h ${WRKSRC}/pine/osdep/os-neb.h.orig
	${SED} -e 's@/usr/local/lib/@${PREFIX}/etc/@' \
		<${WRKSRC}/pine/osdep/os-neb.h.orig >${WRKSRC}/pine/osdep/os-neb.h
	cd ${WRKSRC}/pico && ${MAKE} -f makefile.neb os.h

do-build:
	cd ${WRKSRC} && ./build neb PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/pine/abookcpy ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pine
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.pgp.sample ${PREFIX}/share/examples/pine/
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(mail-directory\)=.*$$|\1=Mail|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/etc/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/etc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/doc/pine/

.include "../../mk/bsd.pkg.mk"
