# $NetBSD: Makefile,v 1.17 2002/09/01 16:34:42 wiz Exp $
#

DISTNAME=	epic4-1.1.6
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-ALPHA/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-ALPHA/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-ALPHA/	\
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-ALPHA/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
