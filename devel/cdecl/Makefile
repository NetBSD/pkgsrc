# $NetBSD: Makefile,v 1.1.1.1 1999/11/11 12:53:16 agc Exp $
#

DISTNAME=	cdecl-2.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/netsw/SoftEng/Lang/C/Tools/cdecl/  \
		ftp://ftp.cc.gatech.edu/ac121/linux/devel/lang/c/  \
		ftp://ftp.deva.net/pub/sources/programming/  \
		ftp://ftp.bitcon.no//pub/linux/linuxberg/files/console/dev/  \
		ftp://ftp.uakom.sk/pub/linux/devel/lang/c/

MAINTAINER=     packages@netbsd.org
#HOMEPAGE=

DEPENDS+=	readline-4.0:../../devel/readline

post-install:
	@${MKDIR} ${PREFIX}/share/doc/cdecl
	${INSTALL_DATA} ${WRKSRC}/testset* ${PREFIX}/share/doc/cdecl

.include "../../mk/bsd.pkg.mk"
