# $NetBSD: Makefile,v 1.20 1999/08/18 09:11:30 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/05/14 10:35:13 torstenb Exp
#

DISTNAME=		ircii-4.4J
PKGNAME=		ircII-4.4J
WRKSRC=			${WRKDIR}/ircii-4.4J
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.au.netbsd.org/pub/ircII/

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	${IRCII_CONFIGURE_ARGS}
CONFIGURE_ENV+=		${IRCII_CONFIGURE_ENV}

PLIST_SRC=		${WRKDIR}/PLIST.tmp

BUILD_DEFS+=		USE_SOCKS

.include "../../mk/bsd.prefs.mk"

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
		find ${PREFIX}/share/irc/help -type f -print | xargs ${GZIP_CMD}; \
	fi
	${RM} -f ${PREFIX}/man/man1/irc.1
	${LN} -s ircII.1 ${PREFIX}/man/man1/irc.1

.include "../../mk/bsd.pkg.mk"
