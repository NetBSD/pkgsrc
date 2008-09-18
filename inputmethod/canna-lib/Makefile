# $NetBSD: Makefile,v 1.10 2008/09/18 12:35:27 taca Exp $

PKGREVISION=	2
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

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

.include "../../mk/bsd.prefs.mk"

# XXX Work around bug in nbitools where the correct DragonFly library
# XXX symlinks are not created.
# XXX
.if ${OPSYS} == "DragonFly"
post-install:
.  for f in RKC RKC16 canna canna16
	${LN} -s lib${f}.so.1.1 ${PREFIX}/lib/lib${f}.so.1
	${LN} -s lib${f}.so.1 ${PREFIX}/lib/lib${f}.so
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
