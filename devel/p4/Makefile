# $NetBSD: Makefile,v 1.2 2002/09/01 02:30:57 schmonz Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/perforce/products/p4.html
COMMENT=	Perforce SCM command-line client

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
