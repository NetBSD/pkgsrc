# $NetBSD: Makefile,v 1.33 2009/05/17 00:03:13 zafer Exp $

DISTNAME=		felt-3.05.src
PKGNAME=		felt-3.05
PKGREVISION=	3
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=felt/}
DISTFILES=		felt-3.05.src.tar.gz felt-3.05.ps.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://felt.sourceforge.net/
COMMENT=		Free system for introductory level finite element analysis

EXTRACT_ONLY=		felt-3.05.src.tar.gz

WRKSRC=			${WRKDIR}/FElt-3.05
USE_X11BASE=		yes
XAW_TYPE?=		3d

MAKE_ENV+=		CCOPTS=${CFLAGS:M*:Q}
MAKE_ENV+=		LDOPTS=${LDFLAGS:M*:Q}
MAKE_ENV+=		SH=${SH:Q}

USE_GNU_READLINE=	# uses remove_history() and history_list()

INSTALLATION_DIRS=	lib/X11/app-defaults share/doc/felt share/examples/felt

post-extract:
	@${GZCAT} ${DISTDIR}/felt-3.05.ps.gz > ${WRKSRC}/felt.ps

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/felt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/felt.ps ${PREFIX}/share/doc/felt
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ FAQ.html README README.old	\
		COPYING CHANGELOG TODO ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/felt

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
