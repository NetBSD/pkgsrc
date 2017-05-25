# $NetBSD: Makefile,v 1.39 2017/05/25 20:41:27 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		ezmlm-idx-${IDXVERSION}
IDXVERSION=		7.2.2
SITES.${DISTNAME}.tar.gz=	http://untroubled.org/ezmlm/archive/${IDXVERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/ezmlm/
COMMENT=		Version of ezmlm with enhancements by third parties
LICENSE=		gnu-gpl-v2

CONFLICTS=		ezmlm-[0-9]*

DISTFILES+=		${EZMLM_VERS}.tar.gz
PLIST_SRC+=		PLIST.idx ${WRKDIR}/PLIST.idx-cf-files

DJB_RESTRICTED=		no
DJB_CONFIG_CMDS+=	${ECHO} ${DESTDIR:Q} > conf-destdir;		\
			${ECHO} ${EGDIR:Q} > conf-egdir;		\
			${ECHO} ${PKG_SYSCONFDIR:Q} > conf-etc;		\
			${ECHO} ${PREFIX}/lib/ezmlm > conf-lib;

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALL_TARGET=		install

PKG_SYSCONFSUBDIR=	ezmlm

.include "cf-files.mk"
.include "cf-dirs.mk"

EGDIR=			${PREFIX}/share/examples/ezmlm-idx
.for file in ${EZMLM_CF_FILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
.for dir in ${EZMLM_CF_DIRS}
OWN_DIRS+=		${PKG_SYSCONFDIR}/${dir}
.endfor

INSTALLATION_DIRS=	bin lib ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/examples/ezmlm-idx

post-extract:
	${GREP} -v '^#' < cf-files.mk | ${CUT} -f2 | ${SED} -e 's|^|share/examples/ezmlm-idx/|g' > ${WRKDIR}/PLIST.idx-cf-files
	${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	${RMDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${DESTDIR}${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${DESTDIR}${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${DESTDIR}${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${DESTDIR}${EGDIR}/ezmlmsubrc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
