# $NetBSD: Makefile,v 1.36 2005/10/04 20:58:43 sketch Exp $

DISTNAME=	abcde_2.3.3.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	audio
MASTER_SITES=	http://www.hispalinux.es/~data/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.hispalinux.es/~data/abcde.php
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	id3v2-[0-9]*:../../audio/id3v2
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	wget>=1.7:../../net/wget

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

EGDIR=		${PREFIX}/share/examples/abcde

MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin man/man1

pre-configure:
	@cd ${WRKSRC} && for f in abcde; do				\
		${SED} "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"		\
			$$f > $$f.tmp &&				\
		${MV} $$f.tmp $$f;					\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/abcde.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
