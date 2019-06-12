# $NetBSD: hacks.mk,v 1.2 2019/06/12 22:04:40 leot Exp $

# devel/glib2 expects modules to end in .so on darwin
# net/glib-networking uses py-meson to build
# py-meson's build.py SharedModule class inherits from SharedLibrary and assumes .dylib suffix
# (true as of py36-meson-0.44.1nb3)

.if ${OPSYS} == "Darwin"
post-install:
	for l in libgiognomeproxy libgiognutls libgiolibproxy libgioopenssl; do \
		if ${TEST} -f "${DESTDIR}${PREFIX}/lib/gio/modules/$${l}.dylib"; then \
			${MV} "${DESTDIR}${PREFIX}/lib/gio/modules/$${l}.dylib" \
				"${DESTDIR}${PREFIX}/lib/gio/modules/$${l}.so"; \
		fi; \
	done
.endif
