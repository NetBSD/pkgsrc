# $NetBSD: Makefile,v 1.4 2006/06/17 20:44:03 rillig Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/perforce/products/p4.html
COMMENT=	Perforce SCM command-line client

P4BINONLY=	yes

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
