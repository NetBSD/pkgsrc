# $NetBSD: Makefile,v 1.20 2023/08/02 19:36:51 nia Exp $

DISTNAME=	mythes-1.2.4
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell}/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Simple thesaurus library
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl:run

GNU_CONFIGURE=	yes

REPLACE_PERL=	th_gen_idx.pl

# Mostly needed due to hunspell headers making c++98 default unacceptable.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

PKGCONFIG_OVERRIDE=	mythes.pc.in

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
