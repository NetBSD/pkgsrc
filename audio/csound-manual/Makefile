# $NetBSD: Makefile,v 1.17 2005/11/10 11:37:39 rillig Exp $
#

DISTNAME=		manual-html-4.23
PKGNAME=		csound-manual-4.23
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/documentation/manuals/ \
			http://www.kevindumpscore.com/download/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound Reference Manual

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}nb2

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/csound
	cd ${WRKSRC}/csound-4.23/manual \
	&& ${PAX} -rw -s '|.*/CVS/.*||' * ${PREFIX}/share/doc/html/csound
	cd ${FILESDIR} && ${INSTALL_DATA} rt-midi-input.* \
		${PREFIX}/share/doc/html/csound/examples
	${LN} -s ../../share/doc/html/csound/examples \
		${PREFIX}/share/examples/csound

.include "../../mk/bsd.pkg.mk"
