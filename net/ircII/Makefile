# New ports collection makefile for:	IrcII Client
# Version required:	2.9
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $NetBSD: Makefile,v 1.8 1998/02/20 07:23:29 hubertf Exp $
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

# Include local make config file here.  It is essential to have this
# precede any override targets (those that override defaults in
# <bsd.port.mk> that test variables that may be set here.  Note that
# this inclusion is otherwise redundant, since <bsd.port.mk> includes
# <bsd.own.mk>, which includes it.

OPSYS!=			uname -s
.if (${OPSYS} == "FreeBSD")
.if exists(/etc/make.conf)
.include "/etc/make.conf"
.endif
.else
.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
.endif

.if defined(MANZ)
DCOMPRESSUFFIX=		.gz
.else
DCOMPRESSUFFIX=
.endif

PLIST_SRC=		${WRKDIR}/PLIST.tmp

pre-install:
	sed "s,@.GZ@,${DCOMPRESSUFFIX}," ${PKGDIR}/PLIST \
		> ${PLIST_SRC}

post-install:
	find ${PREFIX}/lib/irc/help -type f -exec gzip -9 {} \;

.include <bsd.port.mk>
