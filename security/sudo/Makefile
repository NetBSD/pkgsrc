# $NetBSD: Makefile,v 1.49 2002/06/16 20:20:18 wiz Exp $
#

DISTNAME=		sudo-1.6.6
PKGNAME=		${DISTNAME:S/p/./}
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

CONFIGURE_ARGS+=	--disable-root-mailer --disable-setreuid
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-skey
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-skey
.endif

KERBEROS=
.if defined(KERBEROS)
PKG_USE_KERBEROS=	# defined
CONFIGURE_ARGS+=	--with-kerb4 --with-kerb5
CPPFLAGS+=		-I/usr/include/krb5
.else
CONFIGURE_ARGS+=	--without-kerb4 --without-kerb5
.endif

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

PLIST_SRC=		${PKGDIR}/PLIST.common
PLIST_SRC+=		${PKGDIR}/PLIST.${LOWER_OPSYS}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers 0 0 0440

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${EGDIR}/sudoers.sample

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
