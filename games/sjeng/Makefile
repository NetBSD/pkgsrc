# $NetBSD: Makefile,v 1.1.1.1 2001/10/25 04:42:52 jlam Exp $

DISTNAME=	Sjeng-Free-11.0
PKGNAME=	sjeng-11.0
CATEGORIES=	games
MASTER_SITES=	http://sjeng.sourceforge.net/ftp/ \
		${MASTER_SITE_SOURCEFORGE:=sjeng/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://sjeng.sourceforge.net/
COMMENT=	engine for chess variations (bughouse, suicide, etc.)

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=	YES
LIBS+=		-lm			# floor()

MAKE_ENV+=	BOOKDIR="${BOOKDIR}/"

BOOKDIR=	${PREFIX}/lib/sjeng
TBDIR=		${PREFIX}/share/egtb

DOCDIR=		${PREFIX}/share/doc/sjeng
EGDIR=		${PREFIX}/share/examples/sjeng

post-build:
	cd ${WRKSRC};							\
	file="sjeng.rc";						\
	for file in $${files}; do					\
		${SED}	-e "s|/wwwindows/crafty/TB|${TBDIR}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${CAT} ${WRKSRC}/sjeng.rc | ${TR} -d "\015" > ${WRKDIR}/sample.sjengrc
	${INSTALL_DATA} ${WRKDIR}/sample.sjengrc ${EGDIR}
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/books/*.opn ${BOOKDIR}

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
