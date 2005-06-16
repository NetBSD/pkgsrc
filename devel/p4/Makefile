# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/perforce/products/p4.html
COMMENT=	Perforce SCM command-line client

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
