# $NetBSD: Makefile,v 1.17 2001/10/19 09:02:38 veego Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-base-1.12
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support

EXTRACT_CMD=	${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} | ${SH}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g --with-catgets

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != "NetBSD")
PLIST_SRC=	${WRKDIR}/PLIST

post-configure:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile

pre-install:
	-${RM} -f ${WRKDIR}/PLIST
	${CAT} ${PKGDIR}/PLIST | ${SED} -e 's/cat$$/mo/' > ${WRKDIR}/PLIST
.endif

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
