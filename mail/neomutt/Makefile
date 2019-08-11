# $NetBSD: Makefile,v 1.47 2019/08/11 13:21:30 wiz Exp $

DISTNAME=		neomutt-20180716
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=neomutt/}
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.neomutt.org/
COMMENT=		Fork of mutt with integrated community patches
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

USE_TOOLS+=		msgfmt gmake

BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

HAS_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
CONFIGURE_ARGS+=	--notmuch
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

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
.include "../../mail/notmuch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
