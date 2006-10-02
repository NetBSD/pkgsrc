# $NetBSD: Makefile,v 1.1.1.1 2006/10/02 20:06:07 rillig Exp $
#

PROG_CXX=	polyglot
SRCS=		adapter.cpp attack.cpp board.cpp book.cpp book_make.cpp \
		book_merge.cpp colour.cpp engine.cpp epd.cpp fen.cpp	\
		game.cpp hash.cpp io.cpp line.cpp list.cpp main.cpp	\
		move.cpp move_do.cpp move_gen.cpp move_legal.cpp	\
		option.cpp parse.cpp pgn.cpp piece.cpp posix.cpp	\
		random.cpp san.cpp search.cpp square.cpp uci.cpp	\
		util.cpp
LDADD=		-lm
NOMAN=		yes

.include <bsd.prog.mk>
