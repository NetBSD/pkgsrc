# $NetBSD: Makefile,v 1.18 2004/01/20 12:20:24 agc Exp $
#
# NetBSD "imm" package
# The original was based on the imm-3.5a1 FreeBSD port maintained
# by Bill Fenner, but the new one had to be redone completely.
#

DISTNAME=	imm36a1
PKGNAME=	imm-3.6a1
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://tonnant.itd.nrl.navy.mil/ipresearch/imm.html
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

DEPENDS+=       xv>=3.10:../../graphics/xv
DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}/${DISTNAME}.src
USE_X11=	yes
ALL_TARGET=	netbsd

.include "../../mk/bsd.pkg.mk"
