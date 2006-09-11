# $NetBSD: Makefile,v 1.14 2006/09/11 21:26:04 cube Exp $

DISTNAME=	rblcheck-1.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rblcheck.sourceforge.net/
COMMENT=	Command-line interface to Paul Vixie's RBL filter

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

DOCS=		README NEWS docs/rblcheck.ps

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rblcheck
	cd ${WRKSRC} &&						\
		${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/rblcheck

.include "../../mk/bsd.pkg.mk"
