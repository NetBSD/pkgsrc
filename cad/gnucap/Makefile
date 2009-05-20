# $NetBSD: Makefile,v 1.24 2009/05/20 00:58:06 wiz Exp $
#

DISTNAME=	gnucap-2006-07-08
PKGNAME=	gnucap-20060708
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org/
COMMENT=	General purpose circuit simulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	gnucap-2006-07-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES
TEX_DEPMOD=		build
TEX_ACCEPTED=		teTeX3

INSTALLATION_DIRS=	share/gnucap/manual/html

post-install:
	for f in ${WRKSRC}/man/html/*.html ${WRKSRC}/man/html/*.css ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/gnucap/manual/html ; \
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
