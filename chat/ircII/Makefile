# $NetBSD: Makefile,v 1.28 2003/11/25 13:35:20 cjep Exp $

DISTNAME=		ircii-${VERS}
PKGNAME=		ircII-${VERS}
WRKSRC=			${WRKDIR}/ircii-${VERS}
CATEGORIES=		chat
MASTER_SITES=		ftp://ircii.warped.com/pub/ircII/ \
			ftp://ircftp.au.eterna.com.au/pub/ircII/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		The 'Internet Relay Chat' and 'Internet Citizens Band' Client

CONFLICTS=		blackened-[0-9]*

VERS=			20030709
PLIST_SUBST+= 		VERS=${VERS}

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
.if defined(DEFAULT_IRC_SERVER)
CONFIGURE_ARGS+=	--with-default-server=${DEFAULT_IRC_SERVER}
.endif

BUILD_DEFS+=		USE_INET6

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
# (Leave the above line in to still get it into the README-IPv6.html!)

PLIST_SRC=		${WRKDIR}/PLIST.tmp
BUILD_DEFS+=		USE_SOCKS

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.  if ${USE_SOCKS} == 4
.    include "../../net/socks4/buildlink2.mk"
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.socks4}
.  elif ${USE_SOCKS} == 5
.    include "../../net/socks5/buildlink2.mk"
CONFIGURE_ARGS+=	--with-socks5=${BUILDLINK_PREFIX.socks5}
.  endif
.endif

# Allow customizations from /etc/mk.conf.
CONFIGURE_ARGS+=	${IRCII_CONFIGURE_ARGS}
CONFIGURE_ENV+=		${IRCII_CONFIGURE_ENV}

# Solaris
LDFLAGS.SunOS+=	-lsocket -lnsl

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
