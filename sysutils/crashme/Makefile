# $NetBSD: Makefile,v 1.20 2009/06/06 22:21:15 zafer Exp $
#

DISTNAME=		crashme-2.4
CATEGORIES=		sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/historic-linux/early-ports/Sparc/crashme/
				# ftp://ftp.std.com/pub/gjc/

EXTRACT_SUFX=	-shar

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://people.delphiforums.com/gjc/crashme.html
COMMENT=		Try to crash machine with random arguments to random system calls

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

EXTRACT_OPTS=		-f shar
MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.pkg.mk"
