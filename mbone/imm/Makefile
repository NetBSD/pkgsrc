# $NetBSD: Makefile,v 1.12 2000/08/30 23:53:12 jwise Exp $
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

DEPENDS+=	tk-8.3.2:../../x11/tk

USE_X11=	yes
ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include "../../mk/bsd.pkg.mk"
