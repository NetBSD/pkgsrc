# $NetBSD: Makefile,v 1.24 2017/09/25 12:47:44 gson Exp $
#

DISTNAME=		crashme-2.4
CATEGORIES=		sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/historic-linux/early-ports/Sparc/crashme/
#		ftp://ftp.std.com/pub/gjc/

EXTRACT_SUFX=	-shar

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://people.delphiforums.com/gjc/crashme.html
COMMENT=		Try to crash machine by executing random data as instructions

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

EXTRACT_OPTS=		-f shar
MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.pkg.mk"
