# $NetBSD: Makefile,v 1.30 2000/05/04 04:03:54 itojun Exp $
# FreeBSD Id: Makefile,v 1.14 1997/05/14 10:35:13 torstenb Exp
#

DISTNAME=		ircii-4.4S
PKGNAME=		ircII-4.4S
WRKSRC=			${WRKDIR}/ircii-4.4S
CATEGORIES=		net
MASTER_SITES=		ftp://ircftp.au.eterna.com.au/pub/ircII/

MAINTAINER=		packages@netbsd.org

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
.if defined(DEFAULT_IRC_SERVER)
CONFIGURE_ARGS+=	--with-default-server=${DEFAULT_IRC_SERVER}
.endif

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf

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

post-patch:
	@(cd ${WRKSRC}; autoreconf)

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
