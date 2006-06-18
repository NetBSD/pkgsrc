# $NetBSD: Makefile,v 1.25 2006/06/18 07:04:16 rillig Exp $

DISTNAME=	unarj-2.65
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arjsoftware.com/
COMMENT=	Allows files to be extracted from ARJ archives

LICENSE=	unarj-license
RESTRICTED=	Do not charge a fee for use, copying, or distribution
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unarj
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unarj.txt ${PREFIX}/share/doc/unarj
	${INSTALL_MAN} ${WRKSRC}/technote.txt ${PREFIX}/share/doc/unarj

.include "../../mk/bsd.pkg.mk"
