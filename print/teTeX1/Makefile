# $NetBSD: Makefile,v 1.6 2005/04/11 21:47:09 tv Exp $
#

DISTNAME=	teTeX-1.0.7
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	teTeX-bin-1.0.[7-9]*:../teTeX1-bin
DEPENDS+=	teTeX-sharesrc-1.0.[1-9]*:../teTeX1-sharesrc
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

USE_X11=        yes
EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
