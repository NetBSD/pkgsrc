# $NetBSD: Makefile,v 1.17 2007/10/25 22:00:39 jlam Exp $
#

DISTNAME=	mad-0.15.0b
PKGREVISION=	1
CATEGORIES=	audio meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	Meta-package for MAD (MPEG Audio Decoder)

DEPENDS+=	libmad>=0.15.0:../../audio/libmad
DEPENDS+=	libid3tag>=0.15.0:../../audio/libid3tag
DEPENDS+=	madplay>=0.15.0:../../audio/madplay

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
