# $NetBSD: Makefile,v 1.27 2026/06/20 01:09:58 nia Exp $
#

DISTNAME=	crashme-2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/historic-linux/early-ports/Sparc/crashme/
#		ftp://ftp.std.com/pub/gjc/

EXTRACT_SUFX=	-shar

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://people.delphiforums.com/gjc/crashme.html
COMMENT=		Try to crash machine by executing random data as instructions

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

EXTRACT_OPTS=		-f shar
MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}

# This is old code that uses K&R style function definitions.
# Since an evolving C standard is likely to cause compatibility
# problems with it, we force a "known working" standard, in this
# case, the minimum bootstrap requirement, not in strict standard
# mode to ensure no APIs are hidden.
FORCE_C_STD=		gnu99

.include "../../mk/bsd.pkg.mk"
