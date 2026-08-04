# $NetBSD: Makefile,v 1.20 2026/08/04 20:29:02 wiz Exp $

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
	# prepare necessary symlinks to build without configure in server dir
	@${LN} -s ${WRKSRC}/server/*.h ${WRKSRC}/include

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/forcpp ${DESTDIR}${PREFIX}/bin/kpdic

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
