# $NetBSD: Makefile,v 1.9 2019/06/08 11:04:28 rillig Exp $
#

DISTNAME=	GDSreader.0.3.2
PKGNAME=	gdsreader-0.3.2
CATEGORIES=	cad
MASTER_SITES=	http://distcache.FreeBSD.org/local-distfiles/hrs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty, former one not available now
COMMENT=	GDS-II stream file to Postscript and HP/GL converter
LICENSE=	gnu-gpl-v2

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

AUTO_MKDIRS=		yes
INSTALLATION_DIRS=	bin ${EXAMPLESDIR}

do-install:
	for i in gdsreader maptolayer; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin ;\
	done

post-install:
	for i in			\
		README			\
		README.povray		\
		layers.config		\
		layers.config.5AM.4ML	\
		layers.config.7HP.5ML	\
		test.gds		\
		; do			\
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${EXAMPLESDIR} ;\
	done
	for i in			\
		gdsreader.1		\
		maptolayer.1		\
		; do			\
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;\
	done

.include "../../mk/bsd.pkg.mk"
