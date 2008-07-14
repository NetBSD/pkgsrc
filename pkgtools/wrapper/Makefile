# $NetBSD: Makefile,v 1.1.2.4 2008/07/14 05:27:58 schmonz Exp $
#

DISTNAME=		wrapper-20080714
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
