# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:07:20 kei Exp $

DISTNAME=	ja-ptex-1.0
CATEGORIES=	meta-pkgs print japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kei@netbsd.org
COMMENT=	meta-package for pTeX et al, supports Japanese language

DEPENDS+=	ja-ptex-bin>=3.1.2:../../print/ja-ptex-bin
DEPENDS+=	ja-jsclasses>=0.0.0.20021127:../../print/ja-jsclasses
DEPENDS+=	ja-vfxdvik>=22.40v.j1.14:../../print/ja-vfxdvik
DEPENDS+=	dvipdfmx>=0.0.0.20021230nb1:../../print/dvipdfmx

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
