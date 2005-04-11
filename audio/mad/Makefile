# $NetBSD: Makefile,v 1.15 2005/04/11 21:44:54 tv Exp $
#

DISTNAME=	mad-0.15.0b
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

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
