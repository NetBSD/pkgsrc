# $NetBSD: Makefile,v 1.1 2025/08/20 13:32:18 pho Exp $
#
# Replacement Makefile for gkrellm-multiping for portability
#

TARGETS=		pinger multiping.la

PINGER_OBJS=		pinger.lo
PINGER_PKGDEPS=		glib-2.0
PINGER_CFLAGS!=		pkg-config ${PINGER_PKGDEPS} --cflags
PINGER_LIBS!=		pkg-config ${PINGER_PKGDEPS} --libs

MULTIPING_OBJS=		multiping.lo
MULTIPING_PKGDEPS=	gtk+-2.0
MULTIPING_CFLAGS!=	pkg-config ${MULTIPING_PKGDEPS} --cflags
MULTIPING_CFLAGS+=	-DHELPERDIR=\"${HELPER_DIR:Q}\" -DVERSION=\"${VERSION:Q}\"
MULTIPING_LIBS!=	pkg-config ${MULTIPING_PKGDEPS} --libs

.PHONY: all
all: ${TARGETS}

pinger: ${PINGER_OBJS}
	${LIBTOOL} --tag=CC --mode=link \
		${CC} ${LDFLAGS} ${PINGER_LIBS} ${.ALLSRC} -o ${.TARGET}

multiping.la: ${MULTIPING_OBJS}
	${LIBTOOL} --tag=CC --mode=link \
		${CC} ${LDFLAGS} ${MULTIPING_LIBS} ${.ALLSRC} -o ${.TARGET} \
		-module -shared -avoid-version -rpath ${PLUGIN_DIR:Q}

${PINGER_OBJS}: ${.TARGET:.lo=.c}
	${LIBTOOL} --tag=CC --mode=compile \
		${CC} -c ${CFLAGS} ${PINGER_CFLAGS} ${.ALLSRC} -shared

${MULTIPING_OBJS}: ${.TARGET:.lo=.c}
	${LIBTOOL} --tag=CC --mode=compile \
		${CC} -c ${CFLAGS} ${MULTIPING_CFLAGS} ${.ALLSRC} -shared

.PHONY: install
install: ${TARGETS}
	${INSTALL_LIB_DIR} ${DESTDIR}${HELPER_DIR}
	${LIBTOOL} --mode=install ${INSTALL_LIB} pinger ${DESTDIR}${HELPER_DIR}

	${INSTALL_LIB_DIR} ${DESTDIR}${PLUGIN_DIR}
	${LIBTOOL} --mode=install ${INSTALL_LIB} multiping.la ${DESTDIR}${PLUGIN_DIR}
