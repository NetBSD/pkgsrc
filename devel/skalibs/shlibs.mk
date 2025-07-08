# $NetBSD: shlibs.mk,v 1.1 2025/07/08 21:13:37 schmonz Exp $

.PHONY: post-install-skaware-shlib-fake-la-for-plist
post-install: post-install-skaware-shlib-fake-la-for-plist
post-install-skaware-shlib-fake-la-for-plist:
	${RUN} cd ${DESTDIR}${PREFIX}/lib 2>/dev/null || ${TRUE}; \
	for libname in $$(${LS} lib*.${SHLIB_EXT} 2>/dev/null | ${CUT} -d. -f1 | ${SORT} -u); do \
	{ \
		${ECHO} "# not a libtool library file, but suffices for pkgsrc PLIST"; \
		${ECHO} "old_library='$$libname.a'"; \
		${ECHO} "library_names='"$$(${LS} $$libname*.${SHLIB_EXT}*)"'"; \
	} > $$libname.la; \
	done
