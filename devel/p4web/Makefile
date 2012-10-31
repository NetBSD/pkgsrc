# $NetBSD: Makefile,v 1.4 2012/10/31 11:17:35 asau Exp $
#

DISTNAME=	p4web
HOMEPAGE=	http://www.perforce.com/perforce/products/p4web.html
COMMENT=	Perforce SCM Web client

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
