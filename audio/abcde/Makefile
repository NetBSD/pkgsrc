# $NetBSD: Makefile,v 1.7 2002/11/29 02:37:21 kim Exp $

DISTNAME=	abcde-2.0.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/abcde/
DISTFILES=	${DISTNAME:S/-/_/}.orig.tar.gz

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://frantica.lly.org/~rcw/abcde/page/
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	id3v2-[0-9]*:../../audio/id3v2
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	wget>=1.7:../../net/wget

NO_BUILD=	# defined

EGDIR=		${PREFIX}/share/examples/abcde

MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_SYSCONFBASE=${PKG_SYSCONFBASE}

post-patch:
	@cd ${WRKSRC} && for f in abcde abcde.1; do			\
		${SED} "s,@PKG_SYSCONFBASE@,${PKG_SYSCONFBASE},"	\
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
