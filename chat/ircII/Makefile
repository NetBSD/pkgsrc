# $NetBSD: Makefile,v 1.75 2016/02/25 11:28:58 jperkin Exp $

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

VERS=			20151120
PLIST_SUBST+=	VERS=${VERS:Q}

.include "../../mk/bsd.prefs.mk"

# By default, mandir defaults to @datarootdir@/man, and then it gets
# ${DESTDIR} applied already.  However, if you pass --mandir it does
# not provide it, and you have to supply it directly as well.  To do
# this in pkgsrc, we have to set CONFIGURE_HAS_MANDIR=no so that
# we don't pass --mandir=${PREFIX}/man as well, last.
CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=${DESTDIR}${PREFIX}/man

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
LDFLAGS+=	${BUILDLINK_LDADD.iconv}

CONFIGURE_ARGS.Interix+=	--with-non-blocking=none

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
