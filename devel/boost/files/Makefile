# $NetBSD: Makefile,v 1.5 2002/07/07 02:30:52 jschauma Exp $

CXX?=		c++

LIB=		libboost.la

CXXFLAGS+=	# empty
CPPFLAGS+=	-I${.CURDIR} -I${LOCALBASE}/include/sgi-stl

all:	${LIB}

${LIB}:
	${LIBTOOL} ${CXX} ${CXXFLAGS} -o ${.TARGET} ${LOBJS} \
		-rpath ${PREFIX}/lib -version-info ${BOOST_VERS}
