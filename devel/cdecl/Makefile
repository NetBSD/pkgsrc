# $NetBSD: Makefile,v 1.9 2001/06/11 02:05:09 jlam Exp $
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

EGDIR=		${PREFIX}/share/examples/cdecl

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${EGDIR}

.include "../../mk/bsd.pkg.mk"
