# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 06:18:18 lukem Exp $

DISTNAME=	abcde_2.0.orig
PKGNAME=	abcde-2.0
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/abcde/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://frantica.lly.org/~rcw/abcde/page/
COMMENT=	Command-line utility to rip and encode an audio CD

DEPENDS+=	cd-discid>=0.7.0:../../audio/cd-discid
DEPENDS+=	cdparanoia>=3.a9.7:../../audio/cdparanoia
DEPENDS+=	vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=	wget>=1.7:../../net/wget

WRKSRC=		${WRKDIR}/${PKGNAME}

post-patch:
	@cd ${WRKSRC} && for f in abcde abcde.1; do			\
		${SED} "s,@ETCDIR@,${PREFIX}/etc," $$f > $$f.tmp &&	\
		${MV} $$f.tmp $$f;					\
	done

do-build:
	@ :	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/abcde.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
