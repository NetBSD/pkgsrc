# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:32 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/05/14 10:35:13 torstenb Exp
#

DISTNAME=		ircii-4.4Z
PKGNAME=		ircII-4.4Z
WRKSRC=			${WRKDIR}/ircii-4.4Z
CATEGORIES=		chat
MASTER_SITES=		ftp://ircftp.au.eterna.com.au/pub/ircII/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org

.include "../../mk/bsd.prefs.mk"

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
CONFIGURE_ARGS+=	--with-socks${USE_SOCKS}=${PREFIX}
.if ${USE_SOCKS} == 4
DEPENDS+=               socks4-2.2:../../net/socks4
.else
DEPENDS+=               socks5-1.0.2:../../net/socks5
.endif
.endif

pre-install:
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST > ${PLIST_SRC})

post-install:
	@if [ "X${MANZ}" != X"" ]; then \
		${ECHO} Compressing help files; \
		${FIND} ${PREFIX}/share/irc/help -type f -print | xargs ${GZIP_CMD}; \
	fi
	${RM} -f ${PREFIX}/man/man1/irc.1
	${LN} -s ircII.1 ${PREFIX}/man/man1/irc.1

.include "../../mk/bsd.pkg.mk"
