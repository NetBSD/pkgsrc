# $NetBSD: Makefile,v 1.16 2014/02/16 16:59:37 wiedi Exp $

DISTNAME=	gpart-0.1h
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-hannover.de/user/76201/gpart/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brzitwa.de/mb/gpart/index.html
COMMENT=	Tool to show the partitions on a PC type harddisk
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
