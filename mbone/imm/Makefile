# $NetBSD: Makefile,v 1.11 2000/01/09 01:39:14 wiz Exp $
#
# NetBSD "imm" package
# The original was based on the imm-3.5a1 FreeBSD port maintained
# by Bill Fenner, but the new one had to be redone completely.
#

DISTNAME=	imm36a1
PKGNAME=	imm-3.6a1
WRKSRC=		${WRKDIR}/${DISTNAME}.src
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@netbsd.org

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include "../../mk/bsd.pkg.mk"
