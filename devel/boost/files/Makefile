# $NetBSD: Makefile,v 1.2 2000/05/29 22:46:44 jlam Exp $

CXX=		c++

LIB=		libboost.la

SRCS=		libs/timer/prg_display.cpp \
		libs/timer/prg_timer.cpp \
		libs/timer/timer.cpp
OBJS=		${SRCS:.cpp=.lo}
LOBJS=		${OBJS:T}

CXXFLAGS=	# empty
CPPFLAGS+=	-I${.CURDIR} -I${LOCALBASE}/include/sgi-stl

all:	${LIB}

${LIB}:	${LOBJS}
	${LIBTOOL} --cplusplus ${CXX} ${CXXFLAGS} -o ${.TARGET} ${LOBJS} \
		-rpath ${PREFIX}/lib -version-info ${BOOST_VERS}

prg_display.lo:	libs/timer/prg_display.cpp
	${LIBTOOL} ${CXX} ${CXXFLAGS} ${CPPFLAGS} -c ${.ALLSRC}

prg_timer.lo:	libs/timer/prg_timer.cpp
	${LIBTOOL} ${CXX} ${CXXFLAGS} ${CPPFLAGS} -c ${.ALLSRC}

timer.lo:	libs/timer/timer.cpp
	${LIBTOOL} ${CXX} ${CXXFLAGS} ${CPPFLAGS} -c ${.ALLSRC}
