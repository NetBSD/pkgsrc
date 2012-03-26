# This package's distfile has the wonderful idea of containing
# symlinks to various things in /usr/share/automake-1.11/. What
# will they think of next?

BUILD_DEPENDS+=		automake>=1.11<1.12:../../devel/automake

post-extract:
	@echo 'Fixing symlinks to external files'
.for FILE in compile COPYING depcomp INSTALL
	[ -h ${WRKSRC}/${FILE} ] || exit 1
	rm -f ${WRKSRC}/${FILE}
	cp ${PREFIX}/share/automake-1.11/${FILE} ${WRKSRC}/${FILE}
.endfor
