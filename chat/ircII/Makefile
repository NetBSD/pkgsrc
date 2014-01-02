# $NetBSD: Makefile,v 1.62 2014/01/02 07:57:49 mrg Exp $

DISTNAME=		ircii-${VERS}
PKGNAME=		ircII-${VERS}
CATEGORIES=		chat
MASTER_SITES=		http://ircii.warped.com/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eterna.com.au/ircii/
COMMENT=		'Internet Relay Chat' and 'Internet Citizens Band' Client
LICENSE=		modified-bsd

CONFLICTS=		blackened-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

VERS=			20131230
PLIST_SUBST+=	VERS=${VERS:Q}

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/ircii-${VERS}
GNU_CONFIGURE=		yes
.if defined(DEFAULT_IRC_SERVER)
CONFIGURE_ARGS+=	--with-default-server=${DEFAULT_IRC_SERVER:Q}
.endif
USE_TOOLS+=		chmod	# see post-extract

# This pkg auto-detects IPv6.
BUILD_DEFS+=		IPV6_READY

.include "options.mk"

# Allow customizations from ${MAKECONF}
CONFIGURE_ARGS+=	${IRCII_CONFIGURE_ARGS}
CONFIGURE_ENV+=		${IRCII_CONFIGURE_ENV}

LDFLAGS.SunOS+=	-lsocket -lnsl

.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=	--with-non-blocking=none
.endif

# Optionally install compressed help files if MANZ is defined.
.if defined(MANZ)
PLIST_SUBST+=		GZSUFFIX=".gz"
DOC_COMPRESS_ARGS=	-z ${DESTDIR}${PREFIX}
.else
PLIST_SUBST+=		GZSUFFIX=
DOC_COMPRESS_ARGS=	${DESTDIR}${PREFIX}
.endif

post-extract:
	chmod -R g-w ${WRKSRC}/help/.

post-install:
	${AWK} '/^share\/irc\/help\// { sub("\\$${GZSUFFIX}$$", ""); print }' \
		${PLIST_SRC} |						\
	${SETENV} PATH=${PATH:Q} PKG_VERBOSE=${PKG_VERBOSE:Q}		\
	${SH} ${PKGSRCDIR}/mk/plist/doc-compress ${DOC_COMPRESS_ARGS}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
