# $NetBSD: Makefile,v 1.14 2012/10/06 14:25:10 asau Exp $

PKGREVISION=	3
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
.for f in forcpp kpdic
	@${MV} ${WRKSRC}/cmd/${f}/Imakefile ${WRKSRC}/cmd/${f}/Imakefile.orig
	@${SED} -e '/InstallProgram/d' ${WRKSRC}/cmd/${f}/Imakefile.orig \
		> ${WRKSRC}/cmd/${f}/Imakefile
.endfor

MAKE_ENV+=	AWK=${AWK:Q}

post-extract:
	${CP} ${FILESDIR}/dic-phono-filter.awk ${WRKSRC}/dic/phono/

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

.include "../../mk/bsd.pkg.mk"
