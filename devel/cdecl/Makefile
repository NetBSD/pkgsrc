# $NetBSD: Makefile,v 1.12 2002/10/25 18:28:32 wiz Exp $
#

DISTNAME=	cdecl-2.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/softeng/lang/c/tools/cdecl/ \
		ftp://ftp-linux.cc.gatech.edu/pub/linux/devel/lang/c/ \
		ftp://ftp.deva.net/pub/sources/programming/declaration/ \
		ftp://ftp.bitcon.no//pub/linux/linuxberg/files/console/dev/

MAINTAINER=     packages@netbsd.org
COMMENT=	utility to explain and compose C and C++ declarations

USE_BUILDLINK2=		# defined
ALL_TARGET=		cdecl

EGDIR=			${PREFIX}/share/examples/cdecl

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${EGDIR}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
