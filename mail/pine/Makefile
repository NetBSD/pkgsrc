# $NetBSD: Makefile,v 1.13 1998/06/18 15:25:25 agc Exp $
# FreeBSD Id: Makefile,v 1.21 1997/03/26 02:12:07 ache Exp
#
# Note: If you want to have pine's default behaviour of not allowing
# modifications of the From: line, remove the file patch/patch-send
# before you compile. (Keep in mind there are lots and lots of other
# very easy ways of forging that From: line, though.)
#

DISTNAME=       pine3.96
PKGNAME=        pine-3.96
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	packages@netbsd.org

CONFLICTS=	pico-2.9

post-patch:
	${CP} -f ${WRKSRC}/pine/osdep/os-neb.h ${WRKSRC}/pine/osdep/os-neb.h.orig
	${SED} \
	  -e 's|.*\(#define.*SYSTEM_PINERC_FIXED\) .*|\1 "'"${PREFIX}/lib/pine.conf.fixed"'"|g' \
	  -e 's|.*\(#define.*SYSTEM_PINERC\) .*|\1 "'"${PREFIX}/lib/pine.conf"'"|g' \
	  <${WRKSRC}/pine/osdep/os-neb.h.orig >${WRKSRC}/pine/osdep/os-neb.h

do-build:
	cd ${WRKSRC} && ./build neb

do-install:
	${INSTALL_DATA} ${WRKSRC}/pico/libpico.a ${PREFIX}/lib/libpico.a
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin/pilot
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/pgpencrypt
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/pgpdecode
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/pgpsign
	${INSTALL_DATA}    ${FILESDIR}/dot.pinerc.pgp.sample ${PREFIX}/etc/dot.pinerc.pgp.sample
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	${INSTALL_MAN}     ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/pilot.1
	${INSTALL_MAN}     ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(mail-directory\)=.*$$|\1=Mail|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/lib/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/lib/pine.conf.fixed

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine

.include "../../mk/bsd.pkg.mk"
