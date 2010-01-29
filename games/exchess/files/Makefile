# $NetBSD: Makefile,v 1.2 2010/01/29 20:29:26 joerg Exp $

LIBDIR=		${PREFIX}/lib/exchess

CPPFLAGS=	-DEXCHESS_DIR=\"${LIBDIR}/\"

OBJS=		attacks.o book.o check.o exmove.o hash.o main.o movelist.o
OBJS+=		parse.o pcapts.o pmoves.o probe.o score.o search.o setup.o
OBJS+=		sort.o swap.o util.o

all: exchess

exchess: ${OBJS}
	${CXX} -o ${.TARGET} ${OBJS} -lm

.SUFFIXES: .cpp

.cpp.o:
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c ${.IMPSRC}
