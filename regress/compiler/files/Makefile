# $NetBSD: Makefile,v 1.1 2007/03/08 14:31:06 rillig Exp $
#

all: \
	test-preprocessor \
	test-offsetof \
	test-wrapper

test-preprocessor:
	# Test whether CPP is a C preprocessor.
	${CPP} language.c | grep Cplain
.if defined(CXXCPP)
	# Test whether CXXCPP is a C++ preprocessor.
	${CXXCPP} language.cc | grep Cplus
.endif

test-wrapper:
	# Test whether white-space is preserved in macro definitions.
	${CC} checklen.c -o checklen -DLEN=4 -DSPACES=\"\ \ \ \ \" && ./checklen
	${CC} checklen.c -o checklen -DLEN=4 -DSPACES=\""    \"" && ./checklen
	${CC} checklen.c -o checklen -DLEN=4 -DSPACES='"    "' && ./checklen
	# Test whether backslashes are preserved in macro definitions.
	${CC} -c checktype.c -DTYPE="unsigned long"
	${CC} -c checktype.c -DTYPE=unsigned\ long

test-offsetof:
	# Test whether offsetof is available in both C and C++
	${CC} -c offsetof.c
	${CXX} -c offsetof.c
