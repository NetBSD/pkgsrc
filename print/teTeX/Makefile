# $NetBSD: Makefile,v 1.47 2009/02/18 11:16:49 tron Exp $

DISTNAME=	teTeX-3.0
PKGREVISION=	1
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

CONFLICTS+=	teTeX2-[0-9]*

META_PACKAGE=	yes

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
