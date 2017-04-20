# $NetBSD: Makefile,v 1.17 2017/04/20 13:25:07 jperkin Exp $

PKGREVISION=	1
CANNA_MODULE=	lib

.include "../../inputmethod/canna/Makefile.common"

# (1) Change SUBDIRS.
# (2) Don't install `forcpp', `kpdic'.
#
post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED}	-e 's|\(SUBDIRS = lib canna\).*\( misc\)|\1 cmd/forcpp cmd/kpdic dic/phono\2|' \
		-e 's|\(SGSDIR = \).*|\1 lib canna dic/phono misc doc|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

MAKE_ENV+=	AWK=${AWK:Q}

post-extract:
	${CP} ${FILESDIR}/dic-phono-filter.awk ${WRKSRC}/dic/phono/

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/forcpp ${DESTDIR}${PREFIX}/bin/kpdic

.include "../../mk/bsd.pkg.mk"
