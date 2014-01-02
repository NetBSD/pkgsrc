# $NetBSD: Makefile,v 1.17 2014/01/02 04:09:11 dholland Exp $

DISTNAME=	a60-0.20a
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/algol60/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Algol 60 interpreter
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CPPFLAGS+=	-Dunix

INFO_FILES=	yes

INSTALLATION_DIRS=	bin share/a60 share/doc/a60 share/examples/a60 \
			${PKGINFODIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a60 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/a60-mkc.inc				\
		${DESTDIR}${PREFIX}/share/a60/
	set -e; cd ${WRKSRC}; for f in					\
		RRA60.info RRA60.info-[0-9]*				\
		a60.info a60.info-[0-9]*;				\
	do								\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done
	${INSTALL_MAN} ${WRKSRC}/a60.man				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/a60.1
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.a60 README		\
		${DESTDIR}${PREFIX}/share/examples/a60/
	${INSTALL_DATA} ${WRKSRC}/xa60.*				\
		${DESTDIR}${PREFIX}/share/examples/a60/
	cd ${WRKSRC} && ${INSTALL_DATA} a60.ps RRA60.ps			\
		${DESTDIR}${PREFIX}/share/doc/a60/

.include "../../mk/bsd.pkg.mk"
