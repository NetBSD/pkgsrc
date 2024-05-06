# $NetBSD: Makefile,v 1.97 2024/05/06 13:46:13 wiz Exp $

DISTNAME=		neomutt-20240425
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=neomutt/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.neomutt.org/
COMMENT=		Fork of mutt with integrated community patches
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=		w3m-[0-9]*:../../www/w3m
DEPENDS+=		mime-types-[0-9]*:../../misc/mime-types

USE_TOOLS+=		msgfmt gmake perl:build pkg-config

HAS_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

CONFIGURE_ARGS.SunOS+=	--disable-inotify

EGDIR=			${PREFIX}/share/examples/neomutt
CONF_FILES=		${EGDIR}/neomuttrc ${PKG_SYSCONFDIR}/neomuttrc
INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} DOTLOCK_GROUP= sysconfdir=${EGDIR}

GCC_REQD+=		8

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_MESSAGE.interpreter=	Substituting /usr/bin/env python3 interpreter lines
SUBST_FILES.interpreter=	contrib/oauth2/mutt_oauth2.py
SUBST_FILES.interpreter+=	data/account-command/macos-keychain/keychain.py
SUBST_SED.interpreter+=		-e "s,\#! */usr/bin/env *python3,\#!${PYTHONBIN},"

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
