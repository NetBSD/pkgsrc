# $NetBSD: Makefile,v 1.58 2020/11/19 09:35:41 schmonz Exp $
#

DISTNAME=		ezmlm-idx-${IDXVERSION}
PKGREVISION=		13
CATEGORIES=		mail
IDXVERSION=		7.2.2
MASTER_SITES=		http://untroubled.org/ezmlm/archive/${IDXVERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/ezmlm/
COMMENT=		Version of ezmlm with enhancements by third parties
LICENSE=		gnu-gpl-v2

CONFLICTS=		ezmlm-[0-9]*

DEPENDS+=		qmail>=1.03:../../mail/qmail

PLIST_SRC=		${PKGDIR}/../../mail/ezmlm/PLIST ${PKGDIR}/PLIST
PLIST_SRC+=		${WRKDIR}/PLIST.idxcf

DJB_CONFIG_CMDS+=	${ECHO} ${DESTDIR:Q} > conf-destdir;		\
			${ECHO} ${PREFIX:Q}/libexec/cgi-bin > conf-cgibin; \
			${ECHO} ${EGDIR:Q} > conf-egdir;		\
			${ECHO} ${PKG_SYSCONFDIR:Q} > conf-etc;		\
			${ECHO} ${PREFIX:Q}/lib/ezmlm > conf-lib;

LDFLAGS.Darwin+=	-Wl,-U,_FATAL -Wl,-U,_USAGE
LDFLAGS.Linux+=		-Wl,--export-dynamic
LDFLAGS.SunOS+=		-lsocket -lnsl
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

INSTALL_TARGET=		install

PKG_SYSCONFSUBDIR=	ezmlm

.include "cf-files.mk"
.include "cf-dirs.mk"

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
.for file in ${EZMLM_CF_FILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
.for dir in ${EZMLM_CF_DIRS}
OWN_DIRS+=		${PKG_SYSCONFDIR}/${dir}
.endfor

SPECIAL_PERMS+=		${PREFIX}/libexec/cgi-bin/ezmlm-cgi ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 04755

INSTALLATION_DIRS=	bin lib libexec/cgi-bin ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/${PKGBASE} share/examples/${PKGBASE}

.include "options.mk"

post-extract:
	${GREP} -v '^#' < cf-files.mk | ${CUT} -f2 | ${SED} -e 's|^|share/examples/ezmlm-idx/|g' > ${WRKDIR}/PLIST.idxcf

.include "../../mk/bsd.prefs.mk"

post-build:
.if ${OPSYS} == Darwin
	cd ${WRKSRC} && for lib in *.so; do \
	  install_name_tool -id ${PREFIX}/lib/ezmlm/$${lib} $${lib}; \
	done
.endif

do-test:
	cd ${WRKSRC} && ./ezmlm-test

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
.for file in BLURB CHANGES FAQ INSTALL README README.mysql README.pgsql README.std THANKS TODO UPGRADE DOWNGRADE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${DOCDIR}/${file}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
.for file in ezcgi.css ezcgirc ezmlmglrc ezmlmrc ezmlmsubrc
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${EGDIR}/${file}
.endfor

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
