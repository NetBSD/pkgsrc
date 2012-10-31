# $NetBSD: Makefile,v 1.7 2012/10/31 11:17:34 asau Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/perforce/products/p4.html
COMMENT=	Perforce SCM command-line client

P4BINONLY=	yes

NOT_FOR_PLATFORM+=	Linux-*-x86_64

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
