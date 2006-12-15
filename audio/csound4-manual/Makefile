# $NetBSD: Makefile,v 1.2 2006/12/15 14:34:19 wiz Exp $
#

DISTNAME=		manual-html-4.23
PKGNAME=		csound4-manual-4.23
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/documentation/manuals/ \
			http://www.kevindumpscore.com/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound4 Reference Manual

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/csound4
	cd ${WRKSRC}/csound-4.23/manual \
	&& ${PAX} -rw -s '|.*/CVS/.*||' -s ',.*/CVS$$,,' * ${PREFIX}/share/doc/csound4
	cd ${FILESDIR} && ${INSTALL_DATA} rt-midi-input.* \
		${PREFIX}/share/doc/csound4/examples
	${LN} -s ../../share/doc/csound4/examples \
		${PREFIX}/share/examples/csound4

.include "../../mk/bsd.pkg.mk"
