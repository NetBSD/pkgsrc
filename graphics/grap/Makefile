# $NetBSD: Makefile,v 1.20 2014/08/31 21:41:58 wiz Exp $

DISTNAME=	grap-1.45
CATEGORIES=	graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lunabase.org/~faber/Vault/software/grap/
COMMENT=	Language for typesetting graphs
LICENSE=	2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_ext_hash_map=no
USE_LANGUAGES=	c c++
USE_TOOLS+=	lex yacc

.include "../../mk/bsd.pkg.mk"
