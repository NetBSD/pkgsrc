# $NetBSD: Makefile,v 1.17 2003/09/15 11:17:27 agc Exp $

DISTNAME=	abcde-2.1.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.hispalinux.es/~data/files/
DISTFILES=	${DISTNAME:S/-/_/}.orig.tar.gz

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.hispalinux.es/~data/abcde.php
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	id3v2-[0-9]*:../../audio/id3v2
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	wget>=1.7:../../net/wget

NO_BUILD=	# defined

EGDIR=		${PREFIX}/share/examples/abcde

MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

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
