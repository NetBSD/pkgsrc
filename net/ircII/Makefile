# $NetBSD: Makefile,v 1.13 1998/06/21 02:58:31 tv Exp $
# FreeBSD Id: Makefile,v 1.14 1997/05/14 10:35:13 torstenb Exp
#

DISTNAME=		ircii-4.4
PKGNAME=		ircII-4.4
WRKSRC=			${WRKDIR}/ircii-4.4
CATEGORIES=		net
MASTER_SITES=		ftp://ircii.warped.com/pub/ircII/

MAINTAINER=		mrg@eterna.com.au

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-default-server=SERVER[:PORT]

PLIST_SRC=		${WRKDIR}/PLIST.tmp

pre-install:
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST > ${PLIST_SRC})

post-install:
	@if [ "X${MANZ}" != X"" ]; then \
		${ECHO} Compressing help files; \
		find ${PREFIX}/lib/irc/help -type f -print | xargs ${GZIP_CMD}; \
	fi

.include "../../mk/bsd.pkg.mk"
