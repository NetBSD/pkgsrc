# $NetBSD: Makefile,v 1.30 2001/02/05 09:01:03 tron Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=		sudo-1.6.3p5
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.cs.colorado.edu/pub/sudo/ \
			ftp://ftp.uu.net/pub/security/sudo/ \
			ftp://ftp.tux.org/pub/security/sudo/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.courtesan.com/sudo/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		# defined

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-skey
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-skey
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--with-kerb4
.else
CONFIGURE_ARGS+=	--without-kerb4
.endif

.if defined(KERBEROS) && ${KERBEROS} == 5
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--with-kerb5
.else
CONFIGURE_ARGS+=	--without-kerb5
.endif

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

PLIST_SRC=		${PKGDIR}/PLIST.common
PLIST_SRC+=		${PKGDIR}/PLIST.${LOWER_OPSYS}

DOCDIR=			${PREFIX}/share/doc/sudo
EGDIR=			${PREFIX}/share/examples/sudo

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${EGDIR}/sudoers.sample
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
