# $NetBSD: Makefile,v 1.76 2002/01/02 08:36:55 tron Exp $

DISTNAME=		mutt-1.2.5.1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/pub/mutt/ \
			ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
			ftp://ftp.uib.no/pub/mutt/ \
			ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		text-based MIME mail client with PGP support

USE_BUILDLINK_ONLY=	YES

BUILD_USES_MSGFMT=	YES

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/mutt \
			--enable-pop --enable-imap \
			--without-included-gettext
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_DIR}

LDFLAGS+=		${STRIPFLAG}
WRKSRC=			${WRKDIR}/${DISTNAME:S/i//}

.include "../../mk/bsd.prefs.mk"

# There seems to be a problem using NetBSD's /bin/sh, so use /bin/ksh instead.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

MUTT_USE_SSL?=		YES

.if defined(MUTT_USE_SSL) && ${MUTT_USE_SSL} == "YES"
#USE_SSL=		YES
.include "../../security/openssl/buildlink.mk"
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

BUILD_DEFS+=		MUTT_USE_SSL

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${TOUCH} ${TOUCH_FLAGS} ${PREFIX}/share/mutt/.directory
	${INSTALL_DATA} ${WRKSRC}/Muttrc ${PREFIX}/share/doc/mutt/samples
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/share/doc/mutt/samples
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
