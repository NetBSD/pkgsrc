# $NetBSD: Makefile,v 1.21 2008/03/04 12:17:48 wiz Exp $
#

DISTNAME=	gnucap-2006-07-08
PKGNAME=	gnucap-20060708
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org/
COMMENT=	General purpose circuit simulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES
TEX_DEPMOD=		build
TEX_ACCEPTED=		teTeX3

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnucap/manual/html
	for f in ${WRKSRC}/man/html/*.html ${WRKSRC}/man/html/*.css ; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/gnucap/manual/html ; \
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
