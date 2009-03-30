# $NetBSD: Makefile,v 1.1.2.5 2009/03/30 01:02:25 schmonz Exp $
#

DISTNAME=		wrapper-20090329
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://netbsd-soc.sourceforge.net/projects/cwrapper/
COMMENT=		GSoC project to replace pkgsrc/mk/wrapper

NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
PLIST_SRC=		# none

.include "tests.mk"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${DO_NADA}

.include "../../mk/bsd.pkg.mk"
