# $NetBSD: Makefile,v 1.26 2012/10/08 13:25:13 asau Exp $
#

DISTNAME=	gnucap-2006-07-08
PKGNAME=	gnucap-20060708
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org/
COMMENT=	General purpose circuit simulator

BUILD_DEPENDS+=	dvipdfmx>=20100328:../../print/dvipdfmx
BUILD_DEPENDS+=	tex-hyperref>=6.81pnb2:../../print/tex-hyperref

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	gnucap-2006-07-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	share/gnucap/manual/html

post-install:
	for f in ${WRKSRC}/man/html/*.html ${WRKSRC}/man/html/*.css ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/gnucap/manual/html ; \
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
