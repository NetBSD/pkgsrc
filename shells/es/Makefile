# $NetBSD: Makefile,v 1.25 2023/01/16 01:44:21 dholland Exp $

DISTNAME=	es-0.9-alpha1
PKGNAME=	es-0.9a1
PKGREVISION=	5
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.sys.toronto.edu/pub/es/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hawkwind.cs.toronto.edu:8001/mlists/es.html
COMMENT=	Extensible shell, derived from plan9's rc

USE_TOOLS+=	yacc

PKG_SHELL=	bin/es

SUBST_CLASSES=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing path to es in scripts.
SUBST_FILES.path=	esdebug
SUBST_SED.path=		-e 's|^\#! /bin/es|\#! ${PREFIX:Q}/bin/es|'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
