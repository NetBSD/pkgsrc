# $NetBSD: Makefile,v 1.10 1999/04/26 18:56:15 garbled Exp $
#
# NetBSD "imm" package
# The original was based on the imm-3.5a1 FreeBSD port maintained
# by Bill Fenner, but the new one had to be redone completely.
#

DISTNAME=	imm-3.6a1
WRKSRC=		${WRKDIR}/imm36a1.src
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
DISTFILES=	imm36a1.tar.Z

MAINTAINER=	is@netbsd.org

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include "../../mk/bsd.pkg.mk"
