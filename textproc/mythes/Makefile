# $NetBSD: Makefile,v 1.13 2019/08/11 13:23:26 wiz Exp $

DISTNAME=	mythes-1.2.3
PKGREVISION=	7
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

PKGCONFIG_OVERRIDE=	mythes.pc.in

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
