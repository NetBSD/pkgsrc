# $NetBSD: Makefile,v 1.16 2010/02/03 22:13:09 joerg Exp $
#

DISTNAME=	tuxpaint-stamps-2007.07.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Rubber stamps for Tux Paint

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint
CONFLICTS+=	tuxpaint<0.9.13

INSTALL_TARGET=	install-all
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

post-install:
	-${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null

.include "../../mk/bsd.pkg.mk"
