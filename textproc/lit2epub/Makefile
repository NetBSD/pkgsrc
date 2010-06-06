# $NetBSD: Makefile,v 1.1.1.1 2010/06/06 23:41:12 markd Exp $
#

DISTNAME=	ebook-tools-0.1.1
PKGNAME=	lit2epub-0.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ebook-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ebook-tools.sourceforge.net/
COMMENT=	Convert .lit files to valid epub
LICENSE=	mit

DEPENDS+=	zip-[0-9]*:../../archivers/zip
DEPENDS+=	convertlit-[0-9]*:../../textproc/convertlit

CONFLICTS+=	ebook-tools<=0.1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH=	src/tools/lit2epub
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tools/lit2epub ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
