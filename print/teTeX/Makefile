# $NetBSD: Makefile,v 1.38 2005/05/14 02:26:50 reed Exp $
#

DISTNAME=	teTeX-2.0.2
PKGREVISION=	1
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems, version 2

DEPENDS+=	teTeX-bin>=2.0.2:../teTeX-bin
DEPENDS+=	teTeX-sharesrc>=2.0.2:../teTeX-sharesrc
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

CONFLICTS+=	teTeX2-[0-9]*

EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
