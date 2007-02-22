# $NetBSD: Makefile,v 1.11 2007/02/22 19:26:37 wiz Exp $

DISTNAME=	a60-0.20a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/algol60/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Algol 60 interpreter

GNU_CONFIGURE=	yes

CPPFLAGS+=	-Dunix

INFO_FILES=	# PLIST

INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a60 ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/a60/
	${INSTALL_DATA} ${WRKSRC}/a60-mkc.inc ${PREFIX}/share/a60/
	cd ${WRKSRC}; for f in						\
		RRA60.info RRA60.info-[0-9]*				\
		a60.info a60.info-[0-9]*;				\
	do								\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_MAN} ${WRKSRC}/a60.man ${PREFIX}/${PKGMANDIR}/man1/a60.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/a60/
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.a60 README		\
		${PREFIX}/share/examples/a60/
	${INSTALL_DATA} ${WRKSRC}/xa60.* ${PREFIX}/share/examples/a60/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/a60/
	cd ${WRKSRC} && ${INSTALL_DATA} a60.ps RRA60.ps			\
		${PREFIX}/share/doc/a60/

.include "../../mk/bsd.pkg.mk"
