# New ports collection makefile for:	pine
# http://www.washington.edu/pine/
# Version required:     3.96
# Date created:		03 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.2 1997/11/22 05:41:33 hubertf Exp $
#

DISTNAME=       pine3.96
PKGNAME=        pine-3.96
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	ports@FreeBSD.org

MAN1= 		pine.1 pico.1 pilot.1

post-patch:
	[ -f ${WRKSRC}/pine/osdep/os-neb.h.orig ] || \
	  cp ${WRKSRC}/pine/osdep/os-neb.h ${WRKSRC}/pine/osdep/os-neb.h.orig
	sed \
          -e 's|.*\(#define.*SYSTEM_PINERC_FIXED\) .*|\1 "'"${PREFIX}/lib/pine.conf.fixed"'"|g' \
          -e 's|.*\(#define.*SYSTEM_PINERC\) .*|\1 "'"${PREFIX}/lib/pine.conf"'"|g' \
          <${WRKSRC}/pine/osdep/os-neb.h.orig >${WRKSRC}/pine/osdep/os-neb.h

do-build:
	cd ${WRKSRC} && ./build neb

do-install:
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/libpico.so.1.3 ${PREFIX}/lib/libpico.so.1.3
	/sbin/ldconfig -m ${PREFIX}/lib
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/pilot ${PREFIX}/bin/pilot
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/pgpencrypt
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${FILESDIR}/pgpdecode ${PREFIX}/bin/pgpdecode
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${FILESDIR}/pgpsign ${PREFIX}/bin/pgpsign
	install -c -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} ${FILESDIR}/dot.pinerc.pgp.sample ${PREFIX}/etc/dot.pinerc.pgp.sample
	install -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	install -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/pilot.1
	install -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	( echo '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | sed \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(mail-directory\)=.*$$|\1=Mail|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/lib/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/lib/pine.conf.fixed

post-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine

.include <bsd.port.mk>
