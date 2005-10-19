# $NetBSD: Makefile,v 1.1.1.1 2005/10/19 03:36:03 minskim Exp $

DISTNAME=	wsbasic-1_2_4
PKGNAME=	${DISTNAME:S/_/./g}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://wsbasic.sourceforge.net/
COMMENT=	Simple BASIC interpreter

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-install
SUBST_FILES.interpreter=	scripts/*.b
SUBST_SED.interpreter=		-e 's,^\#!\.\./wsbasic,\#!${PREFIX}/bin/wsbasic,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wsbasic ${PREFIX}/bin/
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/wsbasic
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.b ${PREFIX}/share/wsbasic/
	${INSTALL_DATA} ${WRKSRC}/scripts/*.txt ${PREFIX}/share/wsbasic/

.include "../../mk/bsd.pkg.mk"
