# $NetBSD: Makefile,v 1.14 2002/03/21 15:29:50 mrg Exp $

DISTNAME=		ircii-${VERS}
PKGNAME=		ircII-${VERS}
CATEGORIES=		chat
MASTER_SITES=		ftp://ircii.warped.com/pub/ircII/ \
			ftp://ircftp.au.eterna.com.au/pub/ircII/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
COMMENT=		The 'Internet Relay Chat' and 'Internet Citizens Band' Client

CONFLICTS=		blackened-[0-9]*

VERS=			20020321

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
.if defined(DEFAULT_IRC_SERVER)
CONFIGURE_ARGS+=	--with-default-server=${DEFAULT_IRC_SERVER}
.endif

BUILD_DEFS+=		USE_INET6
WRKSRC=			${WRKDIR}/ircii-${VERS}

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
# (Leave the above line in to still get it into the README-IPv6.html!)

PLIST_SRC=		${WRKDIR}/PLIST.tmp
BUILD_DEFS+=		USE_SOCKS

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
CONFIGURE_ARGS+=	--with-socks${USE_SOCKS}=${BUILDLINK_DIR}
.if ${USE_SOCKS} == 4
.include "../../net/socks4/buildlink.mk"
.else
.include "../../net/socks5/buildlink.mk"
.endif
.endif

.if defined(IRCII_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${IRCII_CONFIGURE_ARGS}
.endif
.if defined(IRCII_CONFIGURE_ENV)
CONFIGURE_ENV+=		${IRCII_CONFIGURE_ENV}
.endif

pre-install:
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST > ${PLIST_SRC})

post-install:
	@if [ "X${MANZ}" != X"" ]; then \
		${ECHO} Compressing help files; \
		${FIND} ${PREFIX}/share/irc/help -type f -print | ${XARGS} ${GZIP_CMD}; \
	fi

.include "../../mk/bsd.pkg.mk"
