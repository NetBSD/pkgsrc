# $NetBSD: Makefile,v 1.8 2005/12/29 15:33:45 joerg Exp $
#
.include "../../inputmethod/canna/Makefile.common"

CANNA_MODULE=	lib

INSTALL_TARGET=	install install.man

# (1) Change SUBDIRS.
# (2) Don't install `forcpp', `kpdic'.
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

# We need to pass ${MAKE_ENV} to ${XMKMF}
do-configure:
	@cd ${WRKSRC} && \
	    ${SETENV} ${SCRIPTS_ENV} ${MAKE_ENV} ${XMKMF}

post-configure:
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
post-install:
.for f in RKC RKC16 canna canna16
	${LN} -s lib${f}.so.1.1 ${PREFIX}/lib/lib${f}.so.1
	${LN} -s lib${f}.so.1 ${PREFIX}/lib/lib${f}.so
.endfor
.endif

.include "../../inputmethod/canna/Makefile.include"
