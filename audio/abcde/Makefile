# $NetBSD: Makefile,v 1.4 2001/12/03 18:02:06 wiz Exp $

DISTNAME=	abcde_2.0.orig
PKGNAME=	abcde-2.0
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/abcde/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://frantica.lly.org/~rcw/abcde/page/
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7.0:../../audio/cd-discid
DEPENDS+=	id3-[0-9]*:../../audio/id3
DEPENDS+=	cdparanoia>=3.0.9.7:../../audio/cdparanoia
DEPENDS+=	vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=	wget>=1.7:../../net/wget

WRKSRC=		${WRKDIR}/${PKGNAME}

NO_BUILD=	# defined

post-patch:
	@cd ${WRKSRC} && for f in abcde abcde.1; do			\
		${SED} "s,@ETCDIR@,${PREFIX}/etc," $$f > $$f.tmp &&	\
		${MV} $$f.tmp $$f;					\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/abcde.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
