# $NetBSD: Makefile,v 1.12 2003/12/24 09:53:47 jmmv Exp $
#

DISTNAME=		manual-html-4.23
PKGNAME=		csound-manual-4.23
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/documentation/manuals/ \
			http://www.kevindumpscore.com/download/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound Reference Manual

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/csound
	cd ${WRKSRC}/csound-4.23/manual && \
		${PAX} -rw * ${PREFIX}/share/doc/html/csound
	cd ${FILESDIR} && ${INSTALL_DATA} rt-midi-input.* \
		${PREFIX}/share/doc/html/csound/examples
	${LN} -s ../../share/doc/html/csound/examples \
		${PREFIX}/share/examples/csound

.include "../../mk/bsd.pkg.mk"
