# $NetBSD: Makefile,v 1.3 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	NetBSD1.3I-jman-19990531
PKGNAME=	ja-man-19990531
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.spa.is.uec.ac.jp/pub/NetBSD/jman/archives/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	ftp://ftp.spa.is.uec.ac.jp/pub/NetBSD/jman/index.html
COMMENT=	Japanese on-line manual pages of NetBSD

DEPENDS=	ja-less>=332:../../misc/ja-less
DEPENDS+=	ja-groff-0.99:../../textproc/ja-groff

JAMANDIR=	ja_JP.EUC
PLIST_SUBST+=	JAMANDIR=${JAMANDIR}
MAKE_ENV+=	JAMANDIR=${JAMANDIR}

PLIST_SRC=	${WRKDIR}/PLIST

PKGSRC_USE_TOOLS+=	gtar
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${GTAR} cCf ${PREFIX}/share/groff/tmac - tmac.andoc tmac.doc \
	    mdoc/doc-common mdoc/doc-ditroff mdoc/doc-nroff mdoc/doc-syms | \
	    ${GTAR} xCf ${WRKSRC} -

post-patch:
	@${PATCH} -s -p2 -d ${WRKSRC}/mdoc < \
		${WRKSRC}/jgroff-for-netbsd-jman.dif

do-build:
	@${SED} -e 's|$${BINDIR}|${PREFIX}/bin|g' \
		-e 's|$${JMANCONFDIR}|${PREFIX}/etc|g' ${WRKSRC}/jman/jman.sh \
		> ${WRKSRC}/jman/jman
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|$${X11BASE}|${X11BASE}|g' \
		-e 's|$${JAMANDIR}|${JAMANDIR}|g' \
		${WRKSRC}/jman/jman.conf \
		> ${WRKSRC}/jman/jman.conf.t

MKCATPAGES?=	yes

pre-install:
.if ${MKCATPAGES} == no
	@${SED} -e '/\/cat[1-9]\//d' ${PKGDIR}/PLIST > ${PLIST_SRC}
.if exists(${PKGDIR}/PLIST.${MACHINE})
	@${SED} -e '/\/cat[1-9]\//d' ${PKGDIR}/PLIST.${MACHINE} >> ${PLIST_SRC}
.endif
.else
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if exists(${PKGDIR}/PLIST.${MACHINE})
	@${CAT} ${PKGDIR}/PLIST.${MACHINE} >> ${PLIST_SRC}
.endif
.endif

do-install:
	for f in tmac.andoc tmac.doc \
	    mdoc/doc-common mdoc/doc-ditroff mdoc/doc-nroff mdoc/doc-syms; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} \
			${PREFIX}/share/groff/tmac/$${f}j; \
	 done
	${INSTALL_SCRIPT} ${WRKSRC}/jman/jman ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jman/jman.conf.t ${PREFIX}/etc/jman.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jman
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jman
	@(cd ${WRKSRC}/man; \
		${MAKE} PREFIX='${PREFIX}' JAMANDIR='${JAMANDIR}' install)

.include "../../mk/bsd.pkg.mk"
