# $NetBSD: Makefile,v 1.20 2017/08/16 20:21:03 wiz Exp $
#

DISTNAME=	mad-0.15.0b
PKGREVISION=	1
CATEGORIES=	audio meta-pkgs

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mad/
COMMENT=	Meta-package for MAD (MPEG Audio Decoder)

META_PACKAGE=	# empty

DEPENDS+=	libmad>=0.15.0:../../audio/libmad
DEPENDS+=	libid3tag>=0.15.0:../../audio/libid3tag
DEPENDS+=	madplay>=0.15.0:../../audio/madplay

.include "../../mk/bsd.pkg.mk"
