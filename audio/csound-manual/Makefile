# $NetBSD: Makefile,v 1.18 2006/04/12 20:21:34 rillig Exp $
#

DISTNAME=		manual-html-4.23
PKGNAME=		csound-manual-4.23
PKGREVISION=		4
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/csound
	cd ${WRKSRC}/csound-4.23/manual \
	&& ${PAX} -rw -s '|.*/CVS/.*||' -s ',.*/CVS$$,,' * ${PREFIX}/share/doc/csound
	cd ${FILESDIR} && ${INSTALL_DATA} rt-midi-input.* \
		${PREFIX}/share/doc/csound/examples
	${LN} -s ../../share/doc/csound/examples \
		${PREFIX}/share/examples/csound

.include "../../mk/bsd.pkg.mk"
