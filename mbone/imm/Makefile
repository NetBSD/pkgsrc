# $NetBSD: Makefile,v 1.3 1997/11/24 15:04:25 is Exp $
#
# NetBSD "imm" package
# The original was based on the imm-3.5a1 FreeBSD port maintained
# by Bill Fenner, but the new one had to be redone completely.
#

DISTNAME=	imm-3.6a1
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.hawaii.edu/paccom/imm/
DISTFILES=	imm36a1.tar.Z
WRKSRC=		${WRKDIR}/imm36a1.src

MAINTAINER=	is@netbsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

ALL_TARGET=	netbsd

.include <bsd.port.mk>
