# $NetBSD: Makefile,v 1.1.1.1 2004/11/10 00:46:04 epg Exp $
#

DISTNAME=		mkcmd-8.14
CATEGORIES=		mine
MASTER_SITES=		http://archive.progeny.com/pundits/
EXTRACT_SUFX=		.tgz

MAINTAINER=		epg@NetBSD.org
COMMENT=		Command-line parser and manual page generator

USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin man/man1 man/man5
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
		${PREFIX}/man/man1/mkcmd.1
	${INSTALL_MAN} ${WRKSRC}/lib/mkcmd/mkcmd.man \
		${PREFIX}/man/man5/mkcmd.5

.include "../../mk/bsd.pkg.mk"
