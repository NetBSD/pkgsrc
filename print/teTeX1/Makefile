# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:32 jlam Exp $
#

DISTNAME=	teTeX-1.0.7
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
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
