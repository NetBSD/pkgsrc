# $NetBSD: Makefile,v 1.21 2006/03/04 21:29:13 jlam Exp $
#

DISTNAME=	cdecl-2.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/softeng/lang/c/tools/cdecl/ \
		ftp://ftp-linux.cc.gatech.edu/pub/linux/devel/lang/c/ \
		ftp://ftp.deva.net/pub/sources/programming/declaration/ \
		ftp://ftp.bitcon.no//pub/linux/linuxberg/files/console/dev/

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=	Utility to explain and compose C and C++ declarations

BUILD_TARGET=		cdecl
# missing rl_completion_matches
USE_GNU_READLINE=	yes

EGDIR=			${PREFIX}/share/examples/cdecl

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${EGDIR}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
