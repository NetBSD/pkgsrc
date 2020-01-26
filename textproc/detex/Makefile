# $NetBSD: Makefile,v 1.16 2020/01/26 17:32:13 rillig Exp $

DISTNAME=	detex-2.8
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.purdue.edu/homes/trinkle/detex/
COMMENT=	Remove LaTeX commands
LICENSE=	modified-bsd # nearly

USE_TOOLS+=	lex

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/detex.1l ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/detex.1

.include "../../mk/bsd.pkg.mk"
