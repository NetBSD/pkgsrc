# $NetBSD: Makefile,v 1.1.1.1 1999/06/08 10:01:21 sakamoto Exp $

DISTNAME=	NetBSD1.3I-jman-19990531
PKGNAME=	ja-man-19990531
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.spa.is.uec.ac.jp/pub/NetBSD/jman/archives/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	ftp://ftp.spa.is.uec.ac.jp/pub/NetBSD/jman/index.html

DEPENDS=	ja-less-332:../../japanese/ja-less \
		ja-groff-0.99:../../japanese/groff

PLIST_SRC=	${PKGDIR}/PLIST
.if exists(${PKGDIR}/PLIST.${MACHINE})
PLIST_SRC+=	${PKGDIR}/PLIST.${MACHINE}
.endif

MESSAGE_SRC=    ${PKGDIR}/MESSAGE
MESSAGE_FILE=   ${WRKDIR}/.MESSAGE

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
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${WRKSRC}/jman/jman.conf \
		> ${WRKSRC}/jman/jman.conf.t

pre-install:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|' ${MESSAGE_SRC} > ${MESSAGE_FILE}

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
	@(cd ${WRKSRC}/man; ${MAKE} PREFIX='${PREFIX}' install)

.include "../../mk/bsd.pkg.mk"
