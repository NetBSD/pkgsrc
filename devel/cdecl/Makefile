# $NetBSD: Makefile,v 1.7 2001/05/24 08:53:55 jlam Exp $
#

DISTNAME=	cdecl-2.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/netsw/SoftEng/Lang/C/Tools/cdecl/  \
		ftp://ftp.cc.gatech.edu/ac121/linux/devel/lang/c/  \
		ftp://ftp.deva.net/pub/sources/programming/  \
		ftp://ftp.bitcon.no//pub/linux/linuxberg/files/console/dev/  \
		ftp://ftp.uakom.sk/pub/linux/devel/lang/c/

MAINTAINER=     packages@netbsd.org
COMMENT=	utility to explain and compose C and C++ declarations

ALL_TARGET=	cdecl

.include "../../devel/readline/buildlink.mk"

CFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

EGDIR=		${PREFIX}/share/examples/cdecl

pre-configure: ${BUILDLINK_TARGETS}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${EGDIR}

.include "../../mk/bsd.pkg.mk"
