# $NetBSD: Makefile,v 1.23 2023/07/17 22:00:23 nia Exp $

DISTNAME=	Sjeng-Free-11.0
PKGNAME=	sjeng-11.0
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://sjeng.sourceforge.net/ftp/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=sjeng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sjeng.org/
COMMENT=	Engine for chess variations (bughouse, suicide, etc.)

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
LIBS+=		-lm	# floor()

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

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR} ${BOOKDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${CAT} ${WRKSRC}/sjeng.rc | ${TR} -d "\015" > ${WRKDIR}/sample.sjengrc
	${INSTALL_DATA} ${WRKDIR}/sample.sjengrc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/books/*.opn ${DESTDIR}${BOOKDIR}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
