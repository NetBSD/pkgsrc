# $NetBSD: Makefile,v 1.19 2018/09/02 13:00:55 wiz Exp $

DISTNAME=	tuxpaint-stamps-2018.09.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Rubber stamps for Tux Paint
LICENSE=	gnu-gpl-v2

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint
CONFLICTS+=	tuxpaint<0.9.13

INSTALL_TARGET=	install-all
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

post-install:
	${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
