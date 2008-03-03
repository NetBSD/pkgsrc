# $NetBSD: Makefile,v 1.3 2008/03/03 17:45:36 jlam Exp $
#

DISTNAME=	p4web
HOMEPAGE=	http://www.perforce.com/perforce/products/p4web.html
COMMENT=	Perforce SCM Web client

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
