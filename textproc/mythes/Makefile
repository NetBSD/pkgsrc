# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:08 asau Exp $

DISTNAME=	mythes-1.2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell}/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Library and tools for parsing the visio file format
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl:run

GNU_CONFIGURE=	yes

REPLACE_PERL=	th_gen_idx.pl

PKGCONFIG_OVERRIDE=	mythes.pc.in

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
