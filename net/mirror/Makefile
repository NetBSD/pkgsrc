# $NetBSD: Makefile,v 1.14 2001/09/09 20:36:38 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.9
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	packages@netbsd.org
COMMENT=	Mirror packages on remote sites

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
SCRIPTS_ENV+=	PERL5=${PERL5}

# If you are tempted to add a target that runs ${SED} (or other stuff)
# on the files, please look at scripts/configure first.

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mirror

post-install:
	@if [ ! -f ${PREFIX}/lib/mirror/mirror.defaults ]; then \
	    ${CP} -p \
		${PREFIX}/lib/mirror/mirror.defaults.dist \
		${PREFIX}/lib/mirror/mirror.defaults; \
	fi

.include "../../mk/bsd.pkg.mk"
