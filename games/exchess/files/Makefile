# $NetBSD: Makefile,v 1.1.1.1 2000/10/25 08:40:00 jlam Exp $

BINDIR=		${PREFIX}/bin
LIBDIR=		${PREFIX}/lib/exchess

CPPFLAGS=	-DEXCHESS_DIR=\"${LIBDIR}/\"

OBJS=		attacks.o book.o check.o exmove.o hash.o main.o movelist.o
OBJS+=		parse.o pcapts.o pmoves.o probe.o score.o search.o setup.o
OBJS+=		sort.o swap.o util.o

all: exchess

exchess: ${OBJS}
	${CXX} -o ${.TARGET} ${OBJS} -lm

install: exchess
	${BSD_INSTALL_PROGRAM_DIR} ${BINDIR}
	${BSD_INSTALL_PROGRAM} exchess ${BINDIR}
	${BSD_INSTALL_DATA_DIR} ${LIBDIR}
	${BSD_INSTALL_DATA} search.par ${LIBDIR}

.SUFFIXES: .cpp

.cpp.o:
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c ${.IMPSRC}
