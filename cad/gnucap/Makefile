# $NetBSD: Makefile,v 1.30 2017/01/19 18:52:03 agc Exp $
#

DISTNAME=	gnucap-2006-07-08
PKGNAME=	gnucap-20060708
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/
MASTER_SITES+=	http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org/
COMMENT=	General purpose circuit simulator

BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-hyperref>=6.81pnb2:../../print/tex-hyperref

CONFLICTS+=	gnucap-2006-07-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	share/gnucap/manual/html

post-install:
	for f in ${WRKSRC}/man/html/*.html ${WRKSRC}/man/html/*.css ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/gnucap/manual/html ; \
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
