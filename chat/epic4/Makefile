# $NetBSD: Makefile,v 1.28 2008/01/18 05:06:23 tnn Exp $
#

DISTNAME=	epic4-2.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.eu.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.parodius.com/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

GNU_CONFIGURE=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
