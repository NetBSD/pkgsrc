# $NetBSD: Makefile,v 1.24 2004/10/03 00:13:14 tv Exp $
#

DISTNAME=	epic4-1.2.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-BETA/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-BETA/	\
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-BETA/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
