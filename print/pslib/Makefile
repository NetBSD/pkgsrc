# $NetBSD: Makefile,v 1.7 2006/04/13 18:23:37 jlam Exp $
#

DISTNAME=		pslib-0.2.6
PKGREVISION=		3
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pslib.sourceforge.net/
COMMENT=		C-library to create PostScript files

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libps.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt perl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
