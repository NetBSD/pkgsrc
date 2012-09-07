# $NetBSD: Makefile,v 1.85 2012/09/07 18:36:02 spz Exp $

DISTNAME=		mutt-1.5.21
PKGREVISION=		4
CATEGORIES=		mail
MUTT_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/
MASTER_SITES=		${MUTT_SITES:=devel/}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP & S/MIME support
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/mutt
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-external-dotlock
CONFIGURE_ARGS+=	--enable-pop
CONFIGURE_ARGS+=	--enable-imap

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

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
FILES_SUBST+=		DOCDIR=${DOCDIR}
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	doc/Muttrc
SUBST_VARS.paths+=	DOCDIR PREFIX
SUBST_STAGE.paths=	pre-configure

SPECIAL_PERMS+=	bin/mutt_dotlock ${REAL_ROOT_USER} mail 2551
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
