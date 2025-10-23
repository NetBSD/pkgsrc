# $NetBSD: Makefile,v 1.25 2025/10/23 20:36:43 wiz Exp $

DISTNAME=	ne-3.18
PKGREVISION=	1
CATEGORIES=	editors
#MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://quercite.dx.am/
COMMENT=	Terminal text editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-termcap
MAKE_ENV+=		SHELL=${SH:Q}

BUILD_TARGET=	build

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
