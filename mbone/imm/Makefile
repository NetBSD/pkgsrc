# $NetBSD: Makefile,v 1.15 2003/01/19 07:13:49 salo Exp $
#
# NetBSD "imm" package
# The original was based on the imm-3.5a1 FreeBSD port maintained
# by Bill Fenner, but the new one had to be redone completely.
#

DISTNAME=	imm36a1
PKGNAME=	imm-3.6a1
WRKSRC=		${WRKDIR}/${DISTNAME}.src
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://tonnant.itd.nrl.navy.mil/ipresearch/imm.html
COMMENT=	Internet Image(or other data) Multicaster (and receiver)

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
ALL_TARGET=	netbsd

.include "../../mk/bsd.pkg.mk"
