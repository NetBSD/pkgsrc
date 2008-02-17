# $NetBSD: Makefile,v 1.14 2008/02/17 02:23:52 obache Exp $

DISTNAME=	NetBSD1.3I-jman-19990531
PKGNAME=	ja-man-19990531
PKGREVISION=	3
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# ftp://ftp.spa.is.uec.ac.jp/pub/NetBSD/jman/index.html
COMMENT=	Japanese on-line manual pages of NetBSD

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ja-less>=332:../../misc/ja-less
DEPENDS+=	ja-groff-0.99{,nb*}:../../textproc/ja-groff

JAMANDIR=	ja_JP.EUC
PLIST_SUBST+=	JAMANDIR=${JAMANDIR:Q}
MAKE_ENV+=	JAMANDIR=${JAMANDIR:Q}
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/${JAMANDIR}

PLIST_SRC=	${WRKDIR}/PLIST

USE_TOOLS+=		patch
USE_BSD_MAKE=		yes
MANCOMPRESSED_IF_MANZ=	yes
INSTALLATION_DIRS=	bin share/groff/tmac/mdoc share/examples
.for c in 1 2 3 4 5 6 7 8 9
INSTALLATION_DIRS+=	${PKGMANDIR}/${JAMANDIR}/cat${c}
INSTALLATION_DIRS+=	${PKGMANDIR}/${JAMANDIR}/man${c}
.endfor

INSTALL_DIRS+=	man

CONF_FILES+=	share/examples/jman.conf ${PKG_SYSCONFDIR}/jman.conf

.include "../../mk/bsd.prefs.mk"

post-extract:
	cd ${PREFIX}/share/groff/tmac \
	&& pax -wr tmac.andoc tmac.doc mdoc/doc-common mdoc/doc-ditroff mdoc/doc-nroff mdoc/doc-syms ${WRKSRC}

post-patch:
	patch -s -p2 -d ${WRKSRC}/mdoc ${PATCH_DIST_ARGS} < \
		${WRKSRC}/jgroff-for-netbsd-jman.dif

do-build:
	sed -e 's|$${BINDIR}|${PREFIX}/bin|g' \
		-e 's|$${JMANCONFDIR}|${PKG_SYSCONFDIR}|g' ${WRKSRC}/jman/jman.sh \
		> ${WRKSRC}/jman/jman
	sed -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|$${X11BASE}|${X11BASE}|g' \
		-e 's|$${JAMANDIR}|${JAMANDIR}|g' \
		${WRKSRC}/jman/jman.conf \
		> ${WRKSRC}/jman/jman.conf.t

MKCATPAGES?=	yes

pre-install:
.if ${MKCATPAGES} == no
	sed -e '/\/cat[1-9]\//d' ${PKGDIR}/PLIST > ${PLIST_SRC}
.if exists(${PKGDIR}/PLIST.${MACHINE})
	sed -e '/\/cat[1-9]\//d' ${PKGDIR}/PLIST.${MACHINE} >> ${PLIST_SRC}
.endif
.else
	cp ${PKGDIR}/PLIST ${PLIST_SRC}
.if exists(${PKGDIR}/PLIST.${MACHINE})
	cat ${PKGDIR}/PLIST.${MACHINE} >> ${PLIST_SRC}
.endif
.endif

post-install:
	for f in tmac.andoc tmac.doc \
	    mdoc/doc-common mdoc/doc-ditroff mdoc/doc-nroff mdoc/doc-syms; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} \
			${DESTDIR}${PREFIX}/share/groff/tmac/$${f}j; \
	 done
	${INSTALL_SCRIPT} ${WRKSRC}/jman/jman ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jman/jman.conf.t ${DESTDIR}${PREFIX}/share/examples/jman.conf
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jman
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/jman

.include "../../mk/bsd.pkg.mk"
