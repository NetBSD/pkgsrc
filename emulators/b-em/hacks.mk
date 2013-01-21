# $NetBSD: hacks.mk,v 1.5 2013/01/21 13:51:35 wiz Exp $

# This package's distfile has the wonderful idea of containing
# symlinks into /usr/share/automake-1.11/. What will they think of
# next?

BUILD_DEPENDS+=		automake>=1.13<1.14:../../devel/automake

post-extract:
	@${ECHO} 'Fixing symlinks to external files'
.for file in compile COPYING depcomp INSTALL
	[ -h ${WRKSRC}/${file} ] || exit 1
	rm -f ${WRKSRC}/${file}
	cp ${PREFIX}/share/automake-1.13/${file} ${WRKSRC}/${file}
.endfor
