# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:05 asau Exp $
#

DISTNAME=	ebook-tools-0.1.1
PKGNAME=	lit2epub-0.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ebook-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ebook-tools.sourceforge.net/
COMMENT=	Convert .lit files to valid epub
LICENSE=	mit

DEPENDS+=	convertlit-[0-9]*:../../textproc/convertlit

CONFLICTS+=	ebook-tools<=0.1.1

USE_TOOLS+=	bash:run zip:run
REPLACE_BASH=	src/tools/lit2epub
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tools/lit2epub ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
