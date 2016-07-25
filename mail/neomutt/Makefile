# $NetBSD: Makefile,v 1.2 2016/07/25 09:30:54 wiz Exp $

DISTNAME=		neomutt-20160723
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=neomutt/}
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.neomutt.org/
COMMENT=		Fork of mutt with integrated community patches
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

USE_TOOLS+=		autoconf automake autoreconf

SPECIAL_PERMS+=		bin/mutt_dotlock ${REAL_ROOT_USER} mail 2551
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-external-dotlock
CONFIGURE_ARGS+=	--enable-imap
CONFIGURE_ARGS+=	--enable-notmuch
CONFIGURE_ARGS+=	--enable-pop

EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
INSTALLATION_DIRS+=     ${DOCDIR} ${EGDIR}
INSTALL_MAKE_FLAGS=     ${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mail/notmuch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
