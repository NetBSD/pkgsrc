# $NetBSD: Makefile,v 1.45 2006/07/26 02:21:35 mrg Exp $

DISTNAME=		ircii-${VERS}
PKGNAME=		ircII-${VERS}
CATEGORIES=		chat
MASTER_SITES=		ftp://ircii.warped.com/pub/ircII/ \
			ftp://ircftp.au.eterna.com.au/pub/ircII/ \
			ftp://ftp.sergei.cc/pub/ircII/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eterna.com.au/ircii/
COMMENT=		The 'Internet Relay Chat' and 'Internet Citizens Band' Client

CONFLICTS=		blackened-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

VERS=			20060725
PLIST_SUBST+= 		VERS=${VERS:Q}

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/ircii-${VERS}
GNU_CONFIGURE=		yes
.if defined(DEFAULT_IRC_SERVER)
CONFIGURE_ARGS+=	--with-default-server=${DEFAULT_IRC_SERVER:Q}
.endif

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
# (Leave the line in to still get it into the README-IPv6.html!)
BUILD_DEFS+=		USE_INET6

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
DOC_COMPRESS_ARGS=	-z ${PREFIX}
.else
PLIST_SUBST+=		GZSUFFIX=
DOC_COMPRESS_ARGS=	${PREFIX}
.endif

post-install:
	${AWK} '/^share\/irc\/help\// { sub("\\$${GZSUFFIX}$$", ""); print }' \
		${PLIST_SRC} |						\
	${SETENV} PATH=${PATH:Q} PKG_VERBOSE=${PKG_VERBOSE:Q}		\
	${SH} ${PKGSRCDIR}/mk/plist/doc-compress ${DOC_COMPRESS_ARGS}

.include "../../mk/bsd.pkg.mk"
