# $NetBSD: Makefile,v 1.9 2000/03/26 22:33:17 kim Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.9
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	packages@netbsd.org

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

# If you are tempted to add a target that runs ${SED} (or other stuff)
# on the files, please look at scripts/configure first.

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include "../../mk/bsd.pkg.mk"
