# $NetBSD: Makefile,v 1.21 2002/01/30 23:05:47 jlam Exp $

DISTNAME=		mutt-1.3.27i
PKGNAME=		${DISTNAME:C/i$//}
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/pub/mutt/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		text-based MIME mail client with PGP support

USE_BUILDLINK_ONLY=	YES

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

BUILD_USES_MSGFMT=	YES

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--without-included-gettext \
			--enable-pop --enable-imap

LDFLAGS+=		${STRIPFLAG}
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}

.include "../../mk/bsd.prefs.mk"

.if defined(MUTT_USE_SLANG) && ${MUTT_USE_SLANG} != NO
.include "../../devel/libslang/buildlink.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_DIR}
.else
.include "../../devel/ncurses/buildlink.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_DIR}
.endif

# There seems to be a problem using NetBSD's /bin/sh, so use /bin/ksh instead.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

MUTT_USE_SSL?=		YES

.if defined(MUTT_USE_SSL) && ${MUTT_USE_SSL} == "YES"
.include "../../security/openssl/buildlink.mk"
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

BUILD_DEFS+=		MUTT_USE_SLANG MUTT_USE_SSL
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

EGDIR=			${PREFIX}/share/doc/mutt/samples
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
SUPPORT_FILES=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA} ${WRKSRC}/Muttrc ${PREFIX}/share/doc/mutt/samples
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/share/doc/mutt/samples

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
