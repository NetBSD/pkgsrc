# $NetBSD: Makefile,v 1.7 1998/04/15 10:38:32 agc Exp $
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

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11/tk80

ALL_TARGET=	netbsd
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include "../../mk/bsd.pkg.mk"
