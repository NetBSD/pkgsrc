# $NetBSD: Makefile,v 1.17 2009/06/30 00:07:17 joerg Exp $

DISTNAME=	grap-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lunabase.org/~faber/Vault/software/grap/
COMMENT=	Language for typesetting graphs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_ext_hash_map=no
USE_LANGUAGES=	c c++
USE_TOOLS+=	lex yacc

.include "../../mk/bsd.pkg.mk"
