# $NetBSD: Makefile,v 1.1.2.4 2008/07/13 18:50:21 schmonz Exp $
#

.SUFFIXES: .sh .atf
.sh.atf:
	atf-compile -o ${.TARGET} ${.IMPSRC}

TESTS!=		echo test-*.sh
TESTFILES=	${TESTS:S/.sh$/.atf/g}
ALLFILES=	Atffile ${TESTFILES}

clean:
	rm -f ${ALLFILES}

test: all
	atf-run

all: ${ALLFILES}

Atffile:
	@echo 'Content-Type: application/X-atf-atffile; version="1"' > Atffile
	@echo >> Atffile
	@echo 'prop: test-suite = "regress-buildlink-transform"' >> Atffile
	@echo >> Atffile
.	for i in ${TESTFILES}
	@echo "tp: ${i}" >> Atffile
.	endfor
