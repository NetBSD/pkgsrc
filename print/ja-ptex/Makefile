# $NetBSD: Makefile,v 1.15 2007/10/25 22:01:04 jlam Exp $

DISTNAME=	ja-ptex-1.0
PKGREVISION=	3
CATEGORIES=	meta-pkgs print japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kei@NetBSD.org
COMMENT=	Meta-package for pTeX et al, supports Japanese language

DEPENDS+=	ja-ptex-bin>=3.1.9:../../print/ja-ptex-bin
DEPENDS+=	ja-jsclasses>=030624nb3:../../print/ja-jsclasses
DEPENDS+=	ja-vfxdvik>=22.40v.j1.14nb9:../../print/ja-vfxdvik
DEPENDS+=	dvipdfmx>=0.0.0.20021230nb1:../../print/dvipdfmx

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

MESSAGE_SRC=	${PKGDIR}/MESSAGE

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
