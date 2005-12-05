# $NetBSD: Makefile,v 1.40 2005/12/05 23:55:03 rillig Exp $

DISTNAME=		ircii-${VERS}
PKGNAME=		ircII-${VERS}
#PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		ftp://ircii.warped.com/pub/ircII/ \
			ftp://ircftp.au.eterna.com.au/pub/ircII/ \
			ftp://ftp.sergei.cc/pub/ircII/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.eterna.com.au/ircii/
COMMENT=		The 'Internet Relay Chat' and 'Internet Citizens Band' Client

CONFLICTS=		blackened-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

VERS=			20040820
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

PLIST_SRC=		${WRKDIR}/PLIST.tmp

.include "options.mk"

# Allow customizations from ${MAKECONF}
CONFIGURE_ARGS+=	${IRCII_CONFIGURE_ARGS}
CONFIGURE_ENV+=		${IRCII_CONFIGURE_ENV}

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
