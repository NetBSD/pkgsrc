# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:20 rillig Exp $

DISTNAME=	rename-1.3
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rename/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rename.sourceforge.net/
COMMENT=	Rename recursively with regex patterns
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rename ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rename.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
