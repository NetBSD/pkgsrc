# $NetBSD: Makefile,v 1.1 2023/03/29 15:32:42 joerg Exp $

DISTNAME=	Libertinus-7.040
PKGNAME=	libertinus-ttf-7.040
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=alerque/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	libertinus
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alerque/libertinus
COMMENT=	Libertinus font family
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	share/fonts/X11/OTF
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/static/OTF/*.otf ${DESTDIR}${PREFIX}/share/fonts/X11/OTF

.include "../../mk/bsd.pkg.mk"
