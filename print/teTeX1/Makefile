# $NetBSD: Makefile,v 1.8 2005/07/19 10:15:29 grant Exp $
#

DISTNAME=	teTeX-1.0.7
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	teTeX-bin-1.0.[7-9]*:../../print/teTeX1-bin
DEPENDS+=	teTeX-sharesrc-1.0.[1-9]*:../../print/teTeX1-sharesrc
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
