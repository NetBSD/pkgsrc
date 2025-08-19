# $NetBSD: Makefile,v 1.1 2025/08/19 14:13:16 pho Exp $
#
# Replacement Makefile for gkrellm-snmp for portability
#

OBJS=	gkrellm_snmp.lo

PKG_CONFIG_DEPS=	gtk+-2.0 netsnmp
EXTRA_CFLAGS!=		pkg-config ${PKG_CONFIG_DEPS} --cflags
EXTRA_LIBS!=		pkg-config ${PKG_CONFIG_DEPS} --libs

.PHONY: all
all: gkrellm_snmp.la

gkrellm_snmp.la: ${OBJS}
	${LIBTOOL} --tag=CC --mode=link \
		${CC} ${LDFLAGS} ${EXTRA_LIBS} ${.ALLSRC} -o ${.TARGET} \
		-module -shared -avoid-version -rpath ${PLUGIN_DIR:Q}

.SUFFIXES: .c .lo
.c.lo:
	${LIBTOOL} --tag=CC --mode=compile \
		${CC} -c ${CFLAGS} ${EXTRA_CFLAGS} ${.IMPSRC} -shared

.PHONY: install
install: gkrellm_snmp.la
	${INSTALL_LIB_DIR} ${DESTDIR}${PLUGIN_DIR}
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${.ALLSRC} ${DESTDIR}${PLUGIN_DIR}
