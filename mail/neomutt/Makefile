# $NetBSD: Makefile,v 1.31 2017/08/08 16:38:41 jlam Exp $

DISTNAME=		neomutt-20170714
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=neomutt/}
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.neomutt.org/
COMMENT=		Fork of mutt with integrated community patches
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

USE_TOOLS+=		autoconf automake autoreconf msgfmt gmake

BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
CONFIGURE_ARGS+=	--enable-notmuch
#CONFIGURE_ARGS+=	CFLAGS="-g -O0"

EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
INSTALLATION_DIRS+=     ${EGDIR}
INSTALL_MAKE_FLAGS=     ${MAKE_FLAGS} DOTLOCK_GROUP= sysconfdir=${EGDIR}

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
