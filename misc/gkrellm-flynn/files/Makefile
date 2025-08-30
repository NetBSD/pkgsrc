# $NetBSD: Makefile,v 1.1 2025/08/30 09:25:52 pho Exp $
#
# Replacement Makefile for gkrellflynn for portability
#

OBJS=	gkrellflynn.lo

PKG_CONFIG_DEPS=	gtk+-2.0
EXTRA_CFLAGS!=		pkg-config ${PKG_CONFIG_DEPS} --cflags
EXTRA_CFLAGS+=		-DGKRELLM2
EXTRA_LIBS!=		pkg-config ${PKG_CONFIG_DEPS} --libs

.PHONY: all
all: gkrellflynn.la

gkrellflynn.la: ${OBJS}
	${LIBTOOL} --tag=CC --mode=link \
		${CC} ${LDFLAGS} ${EXTRA_LIBS} ${.ALLSRC} -o ${.TARGET} \
		-module -shared -avoid-version -rpath ${PLUGIN_DIR:Q}

.SUFFIXES: .c .lo
.c.lo:
	${LIBTOOL} --tag=CC --mode=compile \
		${CC} -c ${CFLAGS} ${EXTRA_CFLAGS} ${.IMPSRC} -shared

.PHONY: install
install: gkrellflynn.la
	${INSTALL_LIB_DIR} ${DESTDIR}${PLUGIN_DIR}
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${.ALLSRC} ${DESTDIR}${PLUGIN_DIR}
