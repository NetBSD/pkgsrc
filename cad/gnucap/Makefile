# $NetBSD: Makefile,v 1.32 2022/05/05 13:19:39 nia Exp $
#

DISTNAME=	gnucap-2006-07-08
PKGNAME=	gnucap-20060708
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/
MASTER_SITES+=	http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org/
COMMENT=	General purpose circuit simulator

BUILD_DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
BUILD_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-hyperref>=6.81pnb2:../../print/tex-hyperref

CONFLICTS+=	gnucap-2006-07-[0-9]*

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	share/gnucap/manual/html

post-install:
	for f in ${WRKSRC}/man/html/*.html ${WRKSRC}/man/html/*.css ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/gnucap/manual/html ; \
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
