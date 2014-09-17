# $NetBSD: Makefile,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

.SUFFIXES: .sh .atf
.sh.atf: setup_common.sh
	atf-compile -o ${.TARGET} ${.IMPSRC}

TESTS!=		echo test-*.sh
TESTFILES=	${TESTS:S/.sh$/.atf/g}
ALLFILES=	Atffile ${TESTFILES}

ATF_REPORT?=	atf-report

all: ${ALLFILES}

test: all
	atf-run | ${ATF_REPORT}

clean:
	rm -f ${ALLFILES}

Atffile:
	@echo 'Content-Type: application/X-atf-atffile; version="1"' > Atffile
	@echo >> Atffile
	@echo 'prop: test-suite = "regress-buildlink-transform"' >> Atffile
	@echo >> Atffile
.	for i in ${TESTFILES}
	@echo "tp: ${i}" >> Atffile
.	endfor
