# $NetBSD: Makefile,v 1.6 2007/01/07 09:13:51 rillig Exp $
#

DISTNAME=		mkcmd-8.14
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://archive.progeny.com/pundits/
EXTRACT_SUFX=		.tgz

MAINTAINER=		epg@NetBSD.org
COMMENT=		Command-line parser and manual page generator


INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
PKG_INSTALLATION_TYPES=	overwrite pkgviews

do-build:
	cd ${WRKSRC}/bin/mkcmd && HOSTTYPE= ${SH} ${FILESDIR}/makeme \
		ROOT=${PREFIX} BIN=${PREFIX}/bin LIB=${PREFIX}/lib/mkcmd

do-install:
.for _mkcmd_dir in bin/mkcmd lib/mkcmd
	cd ${WRKSRC}/${_mkcmd_dir} && HOSTTYPE= ${SH} ${FILESDIR}/makeme \
		ROOT=${PREFIX} BIN=${PREFIX}/bin LIB=${PREFIX}/lib/mkcmd \
		install
.endfor
	${INSTALL_MAN} ${WRKSRC}/bin/mkcmd/mkcmd.man \
		${PREFIX}/${PKGMANDIR}/man1/mkcmd.1
	${INSTALL_MAN} ${WRKSRC}/lib/mkcmd/mkcmd.man \
		${PREFIX}/${PKGMANDIR}/man5/mkcmd.5

.include "../../mk/bsd.pkg.mk"
