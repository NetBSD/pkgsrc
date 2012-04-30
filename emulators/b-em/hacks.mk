# $NetBSD: hacks.mk,v 1.3 2012/04/30 21:54:59 dholland Exp $

# This package's distfile has the wonderful idea of containing
# symlinks into /usr/share/automake-1.11/. What will they think of
# next?

BUILD_DEPENDS+=		automake>=1.12<1.13:../../devel/automake

post-extract:
	@echo 'Fixing symlinks to external files'
.for FILE in compile COPYING depcomp INSTALL
	[ -h ${WRKSRC}/${FILE} ] || exit 1
	rm -f ${WRKSRC}/${FILE}
	cp ${PREFIX}/share/automake-1.12/${FILE} ${WRKSRC}/${FILE}
.endfor
