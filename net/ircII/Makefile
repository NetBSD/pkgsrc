# New ports collection makefile for:	IrcII Client
# Version required:	2.9
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $NetBSD: Makefile,v 1.10 1998/03/05 16:55:33 tv Exp $
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

MAN1=			ircII.1 ircbug.1

PLIST_SRC=		${WRKDIR}/PLIST.tmp

pre-install:
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST > ${PLIST_SRC})

post-install:
	@if [ "X${MANZ}" != X"" ]; then \
		echo Compressing help files; \
		find ${PREFIX}/lib/irc/help -type f -print | xargs gzip -9; \
	fi

.include <bsd.port.mk>
