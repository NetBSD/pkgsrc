# $NetBSD: Makefile,v 1.3 2003/07/17 22:52:41 grant Exp $

DISTNAME=	teTeX2-2.0.2
PKGREVISION=	# empty
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems, version 2

DEPENDS+=	teTeX2-bin>=2.0.2:../teTeX2-bin
DEPENDS+=	teTeX2-sharesrc>=2.0.2:../teTeX2-sharesrc
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

USE_BUILDLINK2=	yes
USE_X11=        yes
EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
