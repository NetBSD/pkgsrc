# $NetBSD: Makefile,v 1.17 1999/05/21 20:39:22 tv Exp $
# FreeBSD Id: Makefile,v 1.14 1997/05/14 10:35:13 torstenb Exp
#

DISTNAME=		ircii-4.4I
PKGNAME=		ircII-4.4I
WRKSRC=			${WRKDIR}/ircii-4.4I
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.au.netbsd.org/pub/ircII/

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-default-server=SERVER[:PORT]
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
	(cd ${PREFIX}/man/man1; ${LN} -s ircII.1 irc.1)

.include "../../mk/bsd.pkg.mk"
