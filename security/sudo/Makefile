# $NetBSD: Makefile,v 1.38 2001/08/02 17:27:41 jlam Exp $
#

DISTNAME=		sudo-1.6.3p7
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.cs.colorado.edu/pub/sudo/ \
			ftp://ftp.uu.net/pub/security/sudo/ \
			ftp://ftp.tux.org/pub/security/sudo/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.courtesan.com/sudo/
COMMENT=		Allow others to run commands as root

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-skey
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-skey
.endif

.if defined(KERBEROS)
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--with-kerb4 --with-kerb5
.else
CONFIGURE_ARGS+=	--without-kerb4 --without-kerb5
.endif

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

PLIST_SRC=		${PKGDIR}/PLIST.common
PLIST_SRC+=		${PKGDIR}/PLIST.${LOWER_OPSYS}

DOCDIR=			${PREFIX}/share/doc/sudo
EGDIR=			${PREFIX}/share/examples/sudo

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${EGDIR}/sudoers.sample
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
