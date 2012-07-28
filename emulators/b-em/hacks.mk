# $NetBSD: hacks.mk,v 1.4 2012/07/28 07:13:05 dholland Exp $

# This package's distfile has the wonderful idea of containing
# symlinks into /usr/share/automake-1.11/. What will they think of
# next?

BUILD_DEPENDS+=		automake>=1.12<1.13:../../devel/automake

post-extract:
	@${ECHO} 'Fixing symlinks to external files'
.for file in compile COPYING depcomp INSTALL
	[ -h ${WRKSRC}/${file} ] || exit 1
	rm -f ${WRKSRC}/${file}
	cp ${PREFIX}/share/automake-1.12/${file} ${WRKSRC}/${file}
.endfor
