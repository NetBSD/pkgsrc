# $NetBSD: Makefile,v 1.1.2.2 2002/06/23 18:50:29 jlam Exp $
#

DISTNAME=	joos-0.1
CATEGORIES=     lang
MASTER_SITES=	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

USE_JAVA=	yes

# This is ugly.  The chown should happen after copying, or tar should have
# a way to override permissions.
do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/joos
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/joos -xpf-

.include "../../mk/bsd.pkg.mk"
