# $NetBSD: Makefile,v 1.13 2001/06/20 23:37:01 jlam Exp $

DISTNAME=		felt-3.05.src
PKGNAME=		felt-3.05
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.sourceforge.net/pub/sourceforge/FElt/
DISTFILES=		felt-3.05.src.tar.gz felt-3.05.ps.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://felt.sourceforge.net/
COMMENT=		Free system for introductory level finite element analysis

EXTRACT_ONLY=		felt-3.05.src.tar.gz
WRKSRC=			${WRKDIR}/FElt-3.05

USE_X11BASE=		# defined
USE_XAW=		# defined
XAW_TYPE?=		3d

MAKE_ENV+=		CCOPTS="${CFLAGS}"
MAKE_ENV+=		LDOPTS="${LDFLAGS}"
MAKE_ENV+=		SH="${SH}"

USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# uses remove_history() and history_list()

.include "../../mk/bsd.prefs.mk"
.include "../../devel/readline/buildlink.mk"

.if ${XAW_TYPE} == "3d"
.include "../../x11/Xaw3d/buildlink.mk"
.endif

post-extract:
	@${GZCAT} ${DISTDIR}/felt-3.05.ps.gz > ${WRKSRC}/felt.ps

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/felt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/felt.ps ${PREFIX}/share/doc/felt
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ FAQ.html README README.old	\
		COPYING CHANGELOG TODO ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/felt

.include "../../mk/bsd.pkg.mk"
