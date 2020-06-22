# $NetBSD: Makefile,v 1.59 2020/06/22 06:08:35 wiz Exp $

DISTNAME=		neomutt-20200619
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=neomutt/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.neomutt.org/
COMMENT=		Fork of mutt with integrated community patches
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

USE_TOOLS+=		msgfmt gmake perl:build

BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		w3m-[0-9]*:../../www/w3m

HAS_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

CONFIGURE_ARGS.SunOS+=	--disable-inotify

EGDIR=			${PREFIX}/share/examples/neomutt
CONF_FILES=		${EGDIR}/neomuttrc ${PKG_SYSCONFDIR}/neomuttrc
INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} DOTLOCK_GROUP= sysconfdir=${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
