# $NetBSD: Makefile,v 1.58 2007/04/21 18:27:21 tonio Exp $

DISTNAME=		mutt-1.5.15
CATEGORIES=		mail
MUTT_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/
MASTER_SITES=		${MUTT_SITES:=devel/}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP & S/MIME support

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}		\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-pop					\
			--enable-imap
MAKE_ENV+=		CHGRP=${CHGRP:Q} CHMOD=${CHMOD:Q}

.if (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

# There is a problem using /bin/sh on old NetBSD releases, so use /bin/ksh
# there.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-5]*-*)
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.include "options.mk"

LDFLAGS+=		${_STRIPFLAG_CC}

DOCDIR=			${PREFIX}/share/doc/mutt
EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
FILES_SUBST+=		DOCDIR=${DOCDIR:Q}
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

# Define WRKSRC explicitly so we can use its value below.
WRKSRC=			${WRKDIR}/${DISTNAME}
.if exists(${WRKSRC}/mutt_dotlock)
PLIST_SUBST+=		MUTT_DOTLOCK=
.else
PLIST_SUBST+=		MUTT_DOTLOCK="@comment "
.endif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
