# $NetBSD: Makefile,v 1.21 2003/12/07 15:32:56 wiz Exp $
#

DISTNAME=	epic4-1.2.1
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
USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
