# $NetBSD: Makefile,v 1.19 1999/07/15 06:26:27 mrg Exp $
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
	${LN} -fs ircII.1 ${PREFIX}/man/man1/irc.1

.include "../../mk/bsd.pkg.mk"
