# $NetBSD: Makefile,v 1.27 2009/05/20 00:58:12 wiz Exp $
#

DISTNAME=	cdecl-2.5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netsw.org/softeng/lang/c/tools/cdecl/ \
		ftp://ftp-linux.cc.gatech.edu/pub/linux/devel/lang/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility to explain and compose C and C++ declarations

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		cdecl
# missing rl_completion_matches
USE_GNU_READLINE=	yes
USE_TOOLS+=		lex yacc
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

EGDIR=			${PREFIX}/share/examples/cdecl
INSTALLATION_DIRS=	bin ${EGDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/testset* ${DESTDIR}${EGDIR}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
